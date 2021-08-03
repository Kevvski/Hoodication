#include "pch.h"
#include "ParticleSystem.h"


ParticleSystem::ParticleSystem()
{
}


ParticleSystem::~ParticleSystem()
{
}


void ParticleSystem::initialize(int count) {
	std::srand(time(NULL));

	for (int i = 0; i < count; i++) {
		sf::Vector2f particleSize;
		particleSize.x = static_cast<float>(std::rand() % 15 + 5);
		particleSize.y = particleSize.x;

		sf::Vector2f particlePosition;
		particlePosition.x = static_cast<float>(std::rand() % GameWindow::getWindowSize().x + 0);
		particlePosition.y = static_cast<float>(std::rand() % GameWindow::getWindowSize().y + 0);

		int particlePulseSpeed = std::rand() % 5 + 1;

		particles.push_back(Particle(particleSize, particlePosition, particlePulseSpeed));
	}
}


void ParticleSystem::draw() {
	for (auto particle : particles)
		particle.draw();
}


void ParticleSystem::update() {
	for (auto& particle : particles)
		particle.pulse();
}