#include "PlayerComponent.h"
#include "Engine.h"
void PlayerComponent::Initialize()
{
}

void PlayerComponent::Update(float dt)
{
	Vector2 direction = Vector2{ 1,0 }.Rotate(Math::DegToRad(owner->transform.rotation));

	float rotate = 0;
	float thrust = 0;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) rotate = -1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = 1;
	if (owner->scene->engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) thrust = -1;

	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed);

}

std::unique_ptr<Object> PlayerComponent::Clone()
{
	return std::unique_ptr<Object>();
}

void PlayerComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void PlayerComponent::Write(json_t& value)
{
}