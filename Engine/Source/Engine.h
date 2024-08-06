#pragma once
#include "../Source/Renderer/Renderer.h"
#include "../Source/Input/Input.h"
#include "../Source/Audio/Audio.h"
#include "../Source/Core/ETime.h"
#include "../Source/Math/Vector2.h"
#include "../Source/Math/Random.h"
#include "../Source/Math/MathUtils.h"
#include "../Source/Renderer/Particles.h"
#include "../Source/Renderer/Model.h"
#include "../Source/Math/Transform.h"
#include "../Source/Framework/Actor.h"
#include "../Source/Renderer/ParticleSystem.h"

#include "Resource/Resource.h"
#include "Resource/ResourceManager.h"

#include <SDL.h>
#include <fmod.hpp>


class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	Time& GetTime() { return *m_time; }
	ParticleSystem& GetPS() { return *m_ps; }

	bool IsQuit() { return quit; }

private:
	bool quit = false;

	std::unique_ptr<ParticleSystem> m_ps;
	std::unique_ptr<Time> m_time;
	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input> m_input;
	std::unique_ptr<Audio> m_audio;

};