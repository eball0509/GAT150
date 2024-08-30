#pragma once
#include "Framework/Game.h"
#include "Event/Observer.h"
#include "Event/Event.h"
#include <memory>

class FunGame : public Game, Observer {
public:

	FunGame() = default;
	FunGame(Engine* engine) : Game{ engine } {}


	bool Initialize() override;
	void Shutdown() override;
	void Update(float dt) override;
	void Draw(Renderer& renderer) override;

	void OnPlayerDead(const Event& event);
	void OnAddPoints(const Event& event);

private:
	std::unique_ptr<class Scene> m_scene;

	// Inherited via Game
	void EndGame() override;
};