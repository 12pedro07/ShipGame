#include "Laser.h"
#include "SpriteComponent.h"
#include "Game.h"

#include <iostream>

Laser::Laser(Game* game, Actor* origin, Vector2 start_pos, int direction)
	:Actor(game, "laser_"+origin->name)
	, origin(origin)
	, mRightSpeed(200.0f)
	, direction(direction)
{
	this->SetPosition(start_pos);
	// Create an animated sprite component for the Ship using images of the project
	SpriteComponent* asc = new SpriteComponent(this);
	asc->SetTexture(game->GetTexture("Assets/Laser.png"));
}

//update the Laser moving always forward
void Laser::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime * direction;
	SetPosition(pos);
	if (pos.x > 1024 || pos.x < 0) {
		delete this;
		return;
	}
	this->GetGame()->CheckColision(this);
}

void Laser::Colided(Actor* target)
{
	if (target != origin)
		delete this;
}

Laser::~Laser() {
}