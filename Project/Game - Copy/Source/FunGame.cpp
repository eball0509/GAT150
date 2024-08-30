#include "FunGame.h"
#include "Engine.h"

#include <memory>

bool FunGame::Initialize()
{

    m_scene = std::make_unique<Scene>(m_engine);
    std::string scenenames[] = { "Scenes/tilemap.json","Scenes/scene.json","Scenes/game.json" };
    for (auto sceneName : scenenames) {
        rapidjson::Document doc;
        Json::Load(sceneName, doc);
        m_scene->Read(doc);

    }

    m_scene->Initialize();

    //ADD_OBSERVER(PlayerDead, TheGame::OnPlayerDead)
    //ADD_OBSERVER(AddPoints, TheGame::OnAddPoints)



    return true;
}

void FunGame::Shutdown()
{
    m_scene->RemoveAll();
}

void FunGame::Update(float dt)
{
    m_scene->Update(dt);
}

void FunGame::Draw(Renderer& renderer)
{
    m_scene->Draw(renderer);
}

void FunGame::OnPlayerDead(const Event& event)
{
    std::cout << "Player Dead\n";
}

void FunGame::OnAddPoints(const Event& event)
{
}