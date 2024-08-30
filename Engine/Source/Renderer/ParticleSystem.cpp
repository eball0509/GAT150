#include "ParticleSystem.h"

void ParticleSystem::Update(float dt)
{
	for (auto& particle : m_particles) {
		if (particle.isActive) particle.update(dt);
	}
}

void ParticleSystem::Draw(Renderer& renderer)
{
	for (auto& particle : m_particles) {
		renderer.SetColor(particle.r, particle.g, particle.b, 1);
		if (particle.isActive) particle.draw(renderer);
	}
}

void ParticleSystem::AddParticle(const Particle::Data& data)
{
	Particle* particle = GetFreeParticle();
	if (particle) {
		particle->Initialize(data);
	}
}

Particle* ParticleSystem::GetFreeParticle()
{
	for (auto& particle : m_particles) {
		if (!particle.isActive) return &particle;
	}
	return nullptr;
}
