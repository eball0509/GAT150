#pragma once
#include "Renderer/Renderer.h"
#include "Renderer/Particles.h"
#include "Renderer/Model.h"
#include "Renderer/Font.h"
#include "Framework/Actor.h"

#include "Input/Input.h"

#include "Audio/Audio.h"

#include "Core/Factory.h"
#include "Core/ETime.h"
#include "Core/Json.h"
#include "Core/EString.h"

#include "Math/Vector2.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"

#include "Renderer/ParticleSystem.h"
#include "Framework/Scene.h"


#include "Resource/Resource.h"
#include "Resource/ResourceManager.h"

#include "Components/TextureComponent.h"
#include "Components/TextComponent.h"
#include "Components/EnginePhysicsComponent.h"
#include "Components/ButtonComponent.h"

#include "Physics/Physics.h"

#include <SDL.h>
#include <fmod.hpp>
#include <rapidjson/document.h>
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
	Physics& GetPhysics() { return *m_physics; }
	std::unique_ptr<Physics> m_physics;

};