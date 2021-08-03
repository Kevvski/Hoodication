#pragma once
#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include <cstdio>
#include <ctime>
#include <vector>
#include "Particle.h"


class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void initialize(int count = 10);
	void draw();
	void update();

private:
	std::vector<Particle> particles;
};

#endif // !PARTICLESYSTEM_H

