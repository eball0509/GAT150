#pragma once
#include "Resource/Resource.h"
#include "Math/Vector2.h"
#include "Renderer.h"

class Texture : public Resource
{

public:
	
	Texture() = default;
	Texture(SDL_Texture* texture) : m_texture{ texture } {}
	~Texture();

	bool Load(const std::string& filename, class Renderer& renderer);

	Vector2 GetSize();

	friend class Renderer;

	bool Create(std::string filename, ...) override;

private:
	
	SDL_Texture* m_texture{ nullptr };

};