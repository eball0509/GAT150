#include "Engine.h"
#include "Framework/Scene.h"
#include "Framework/Actor.h"
#include "Renderer/Texture.h"
#include "Core/EAssert.h"
#include "Renderer/Text.h"
#include "Core/EFile.h"
#include "Core/Json.h"
#include "Components/PlayerComponent.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <SDL_image.h>



int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypeName());
	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypeName());
	Factory::Instance().Register<EnginePhysicsComponent>(EnginePhysicsComponent::GetTypeName());
	Factory::Instance().Register<PlayerComponent>(PlayerComponent::GetTypeName());
	Factory::Instance().Register<TextComponent>(TextComponent::GetTypeName());
	Factory::Instance().Register<ButtonComponent>(ButtonComponent::GetTypeName());

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

	//__LINE__ Prints the line
	//__FILE__ Prints the current file
	//__FUNCTION__ Prints the function

	std::string s;
	File::ReadFile("json.txt", s);
	//std::cout << s;

	rapidjson::Document document;
	Json::Load("json.txt", document);

	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	scene->Read(document);
	scene->Initialize();

	auto* actor = scene->GetActor<Actor>("text");
	while (!engine->IsQuit())
	{
		engine->Update();
		scene->Update(engine->GetTime().GetDeltaTime());

		if (actor)
		{
			actor->transform.rotation += 10;
		}

		ButtonComponent* btnComp = new ButtonComponent();
		btnComp->OnClick(engine->GetRenderer(), []() -> bool {return true; });

		engine->GetRenderer().SetColor(255, 255, 255, 0);
		engine->GetRenderer().BeginFrame();


		scene->Draw(engine->GetRenderer());
		engine->GetPS().Update(engine->GetTime().GetDeltaTime());
		engine->GetRenderer().EndFrame();

	}
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}