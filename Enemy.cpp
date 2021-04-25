#include "Enemy.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "Laser.h"
#include "Item.h"
#include "Timer.h"

#include <iostream>

Enemy::Enemy(Game* game)
	:Actor(game, "enemy", true)
	, laserAvailable(true)
	, mDownSpeed(40.0f)
{
	// Create an animated sprite component for the Ship using images of the project
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Enemy01.png"),
		game->GetTexture("Assets/Enemy02.png"),
		game->GetTexture("Assets/Enemy03.png"),
		game->GetTexture("Assets/Enemy04.png"),
		game->GetTexture("Assets/Enemy05.png"),
		game->GetTexture("Assets/Enemy06.png")
	};
	//set the textures to the Ship vector of animated sprites
	asc->SetAnimTextures(anims);
	int randY = 0 + (rand() % (769));
	int randX = 700 + (rand() % (1024 - 701));
	this->initPos = Vector2((float)randX, (float)randY);
	this->SetPosition(this->initPos);
	// Restrict movements in bounds and select direction
	this->bound_up = this->initPos.y + 50 > 743 ? 743 : this->initPos.y + 50;
	this->bound_down = this->initPos.y - 50 < 25 ? 25 : this->initPos.y - 50;
}

void Enemy::UpdateActor(float deltaTime)
{
	//update the Ship following modifications made by the ProcessKeyboard
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	mDownSpeed = pos.y > this->bound_up || pos.y < this->bound_down ? mDownSpeed * -1 : mDownSpeed;
	pos.y += mDownSpeed * deltaTime;
	SetPosition(pos);

	if (this->laserAvailable) {
		this->laserAvailable = false;
		Game* game = this->GetGame();
		new Laser(game, this, this->GetPosition() - Vector2(50, 0), -1);
		int rand_time = 1000 + (rand() % (7999));
		Timer::timer(rand_time, &(Enemy::LaserRecharge), this);
	}
}

void Enemy::Colided(Actor* target)
{
	int rand_chance = (rand() % 9);
	if(rand_chance > 0)
	{
		new Item(this->GetGame(), this, this->GetPosition());
	}

	this->SetState(EDead);
}

void Enemy::LaserRecharge(void* origin)
{
	Enemy* enemy = static_cast<Enemy*>(origin);
	enemy->laserAvailable = true;
}
