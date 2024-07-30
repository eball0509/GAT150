#include "Engine.h"
#include "Scene.h"

#include <iostream>
#include <cstdlib>
#include <vector>


int main(int argc, char* argv[])
{
	g_engine.Initialize();

	while (!g_engine.IsQuit())
	{
		g_engine.Update();

		g_engine.GetRenderer().SetColor(255, 255, 255, 0);
		g_engine.GetRenderer().BeginFrame();

		g_engine.GetRenderer().EndFrame();
	}
	return 0;
}
