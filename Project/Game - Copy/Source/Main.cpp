#include "Engine.h"
#include "FunGame.h"

#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char* argv[]) {

	//load assets
	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	//create engine
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

	//create game
	std::unique_ptr<FunGame> game = std::make_unique<FunGame>(engine.get());
	game->Initialize();


	while (!engine->IsQuit()) {

		//update
		engine->Update();
		game->Update(engine->GetTime().GetDeltaTime());

		//draw
		engine->GetRenderer().SetColor(0, 0, 0, 0);
		engine->GetRenderer().BeginFrame();

		game->Draw(engine->GetRenderer());

		//stop drawing
		engine->GetRenderer().EndFrame();
	}

	//free's up memory before closing
	game->Shutdown();
	ResourceManager::Instance().Clear();
	engine->Shutdown();
	return 0;
}