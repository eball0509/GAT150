#pragma once
#include "Math/Transform.h"
#include "Scene.h"
#include "Components/Component.h"

#include <string>
#include <memory>
#include <vector>
#include <functional>

class Renderer;

class Actor : public Object{
public:
	Actor() = default;
	Actor(const Transform& transform) : transform{ transform } {}
	Actor(const Actor& other);

	CLASS_DECLARATION(Actor)
	CLASS_PROTOTYPE(Actor)

	friend class Scene;
	
	void Initialize();

	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);

	std::function<void(Actor*)> OnCollisionEnter;
	std::function<void(Actor*)> OnCollisionExit;

	void AddComponent(std::unique_ptr<Component> component);

	template<typename T>
	T* GetComponent();

	template<typename T>
	std::vector<T*> GetComponents();

public:
	std::string tag;
	float lifespan = 0;
	bool destroyed = false;
	Transform transform ;
	Scene* scene{ nullptr };
	bool active = false;

protected:

	std::vector<std::unique_ptr<Component>> components;
};
template<typename T>
 inline T* Actor::GetComponent()
{
	 for (auto& component : components) {
		 T* result = dynamic_cast<T*>(component.get());
		 if (result) return result;
	 }
	return nullptr;
}

 template<typename T>
 inline std::vector<T*> Actor::GetComponents() {

	 std::vector<T*> results;

	 for (auto& component : components) {
		 T* result = dynamic_cast<T*>(component.get());
		 if (results) results.pushBack(result);
	 }
	 return results;
 }