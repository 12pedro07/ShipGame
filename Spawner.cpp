#include "Spawner.h"
#include "Timer.h"
#include "Game.h"

#include <iostream>

Spawner::Spawner(Game* game) :
	Actor(game, "spawner"),
	cooldown(5000),
	nEnemies(1),
	nEnemiesSimultaneous(3),
	ready(true)
{
	this->Enemies = std::vector<Enemy*>();
	this->SetPosition(Vector2(10000, 10000));
}

Spawner::~Spawner()
{
	
}

void Spawner::UpdateActor(float deltaTime)
{
	for (unsigned int i = 0; i < this->Enemies.size(); i++) {
		Enemy* enemy = this->Enemies[i];
		if (enemy == nullptr) {
			this->Enemies.erase(this->Enemies.begin()+i);
		}
	}

	if (this->ready) 
	{
		for (int i = 0; i < this->nEnemiesSimultaneous; i++) {
			if ((int)this->Enemies.size() < this->nEnemies) {
				this->Enemies.push_back(new Enemy(this->GetGame()));
			}
		}
		if ((int)this->Enemies.size() < this->nEnemies) {
			Timer::timer(this->cooldown, &(Spawner::CooldownCallback), this);
		}
		this->ready = false;
	}
}

void Spawner::CooldownCallback(void* origin)
{
	Spawner* spawner = static_cast<Spawner*>(origin);
	if ((int)spawner->Enemies.size() < spawner->nEnemies) {
		std::cout << "Ready for the next wave!!!" << std::endl;
		spawner->ready= true;
	}
}

