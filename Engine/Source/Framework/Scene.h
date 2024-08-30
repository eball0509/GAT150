#pragma once
#include "Object.h"
#include "Core/EAssert.h"

#include <list>
#include <memory>

class Engine;
class Renderer;
class Actor;
class Game;

class Scene : public Object {
public:
	Scene(Engine* engine, Game* game = nullptr) :engine{ engine }, game{ game } {}
	Scene(const Scene& other) { ASSERT(false); }

	CLASS_DECLARATION(Scene)
	CLASS_PROTOTYPE(Scene)

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor, bool initialize = false);
	void RemoveAll();

	template<typename T> T* GetActor();
	template<typename T> T* GetActor(const std::string& name);

	void Initialize() override;

	Game* GetGame() { return game; };
public:
	Engine* engine{ nullptr };
	Game* game{ nullptr };

protected:
	std::list<std::unique_ptr<Actor>> actors;
};

template<typename T>
T* Scene::GetActor() {

	for (auto& actor : actors) {
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}
	return nullptr;
}

template<typename T>
inline T* Scene::GetActor(const std::string& name)
{
	for (auto& actor : actors) {
		T* result = dynamic_cast<T*>(actor.get());
		if (result && IsEqualIgnoreCase(result->name, name)) return result;
	}
	return nullptr;
}