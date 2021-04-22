#pragma once
#include "Actor.h"
class Laser : public Actor
{
public:
	Laser(class Game* game, Actor* origin, Vector2 start_pos, int direction=1);
	virtual ~Laser();
	void UpdateActor(float deltaTime) override;
	float GetRightSpeed() const { return mRightSpeed; }
	void Colided(Actor* target) override;
private:
	float mRightSpeed;
	int direction;
	Actor* origin;
};

