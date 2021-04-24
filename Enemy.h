#pragma once
#include "Actor.h"
class Enemy :
    public Actor
{
	//as Ship will be controlled, it needs proper methods for it
public:
	Enemy(class Game* game);
	void UpdateActor(float deltaTime) override;
	void Colided(Actor* target) override;
	float GetDownSpeed() const { return mDownSpeed; }
private:
	float mDownSpeed;
	bool laserAvailable; // Booleano que diz se a nave pode ou nao atirar
	static void LaserRecharge(void* origin); // callback que espera ate recarregar o laser
	Vector2 initPos;
	float bound_up;
	float bound_down;
};