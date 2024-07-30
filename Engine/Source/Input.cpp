#include "Input.h"
#include <SDL.h>

bool Input::Initialize()
{
	int numKeys;
	const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);
	k_keyboardState.resize(numKeys);

	copy(keyboardState, keyboardState + numKeys, k_keyboardState.begin());

	k_prevKeyboardState = k_keyboardState;

	return true;
}

void Input::Shutdown()
{
}

void Input::Update()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	k_keyboardState = k_prevKeyboardState;
	const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
	copy(keyboardState, keyboardState + k_keyboardState.size(), k_keyboardState.begin());
	
	int x, y;
	uint32_t buttonState = SDL_GetMouseState(&x,&y);

	m_mousePosition.x = (float)x;
	m_mousePosition.y = (float)y;

	m_prevMouseButtonStates = m_mouseButtonStates;

	m_mouseButtonStates[0] = buttonState & SDL_BUTTON_LMASK;
	m_mouseButtonStates[1] = buttonState & SDL_BUTTON_MMASK;
	m_mouseButtonStates[2] = buttonState & SDL_BUTTON_RMASK;
}
