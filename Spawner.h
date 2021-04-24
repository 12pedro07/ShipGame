#pragma once
#include "Actor.h"
#include "Enemy.h"
#include <vector>
class Spawner : public Actor
{
public:
	Spawner(class Game* game);
	virtual ~Spawner();
	void UpdateActor(float deltaTime) override;
private:
	int nEnemies;
	int nEnemiesSimultaneous;
	int cooldown;
	bool ready;
	std::vector<Enemy*> Enemies;
	static void CooldownCallback(void* origin);
	int level;
};