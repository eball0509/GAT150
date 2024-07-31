#include "Engine.h"
#include "..//Engine/Source/Framework/Scene.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>


int main(int argc, char* argv[])

{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();
	engine->Initialize();

#ifdef _DEBUG
	std::cout << "debug\n";
#endif



	while (!engine->IsQuit())
	{
		engine->Update();

		engine->GetRenderer().SetColor(255, 255, 255, 0);
		engine->GetRenderer().BeginFrame();

		engine->GetRenderer().EndFrame();

	}
	engine->Shutdown();

	return 0;
}
