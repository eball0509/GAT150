#include "Engine.h"
#include "Framework/Scene.h"
#include "Framework/Actor.h"
#include "Renderer/Text.h"
#include "Renderer/Texture.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"
#include "Core/Json.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <SDL_image.h>


int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();
	
	std::string s;
	File::ReadFile("json.txt", s);
	std::cout << s;

	rapidjson::Document document;
	Json::Load("json.txt", document);

	std::string name;
	int age;
	bool isAwake;

	READ_DATA(document, name);
	READ_DATA(document, age);
	READ_DATA(document, isAwake);

	std::cout << name << " " << age << " " << isAwake << std::endl;



	{
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("dice.jpg", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ArcadeClassic.ttf", 20);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hola", { 1, 0, 0, 1 });

		Transform t({ 30, 30 });
		std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
		std::unique_ptr<TextureComponent> component = std::make_unique<TextureComponent>();
		component->texture = texture;
		actor->AddComponent(std::move(component));

		while (!engine->IsQuit())
		{
			engine->Update();

			actor->Update(engine->GetTime().GetDeltaTime());

			engine->GetRenderer().SetColor(255, 255, 255, 0);
			engine->GetRenderer().BeginFrame();

			//engine->GetRenderer().DrawTexture(texture.get(), 30, 30);
			text->Draw(engine->GetRenderer(), engine->GetRenderer().GetWidth() - 200, 20);
			actor->Draw(engine->GetRenderer());
			engine->GetPS().Update(engine->GetTime().GetDeltaTime());
			
			engine->GetRenderer().EndFrame();


		}
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}
