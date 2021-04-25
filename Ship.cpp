// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Ship.h"
#include "AnimSpriteComponent.h"
#include "Game.h"
#include "Timer.h"
#include "Laser.h"

#include <thread>
#include <chrono>


Ship::Ship(Game* game)
	:Actor(game, "ship", true)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
	,laserAvailable(true)
	,laserRechargeTime(500)
	,lives(1)
{
	// Create an animated sprite component for the Ship using images of the project
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png"),
	};
	//set the textures to the Ship vector of animated sprites
	asc->SetAnimTextures(anims);
}

//update the Ship following modifications made by the ProcessKeyboard
void Ship::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;
	// Restrict position to left half of screen
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > 500.0f)
	{
		pos.x = 500.0f;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;
	}
	SetPosition(pos);
}

void Ship::Colided(Actor* target)
{
	if (target->name == "item_enemy") 
	{
		if (laserRechargeTime > 0) {
			this->laserRechargeTime -= 100;
			Timer::timer(10000, &(Ship::RemoveItem), this);

		}
		return;
	}
	this->lives--;
	if (this->lives == 0)
	{
		this->SetState(EDead);
	}
}

//Get inputs by Keyboard
//this method will change the speed of the Ship
//Remember that the speed is given by some amount of pixels drawn in a given delta time
void Ship::ProcessKeyboard(const uint8_t* state)
{
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[this->right_key])
	{
		mRightSpeed += 250.0f;
	}
	if (state[this->left_key])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[this->down_key])
	{
		mDownSpeed += 300.0f;
	}
	if (state[this->up_key])
	{
		mDownSpeed -= 300.0f;
	}
	// space
	if (state[this->shot_key])
	{
		if (this->laserAvailable) {
			this->laserAvailable = false;
			Game* game = this->GetGame();
			new Laser(game, this, this->GetPosition() + Vector2(50,0));
			Timer::timer(this->laserRechargeTime, &(Ship::LaserRecharge), this);
		}
	}
}

void Ship::SetControls(SDL_Scancode left, SDL_Scancode right, SDL_Scancode up, SDL_Scancode down, SDL_Scancode shot)
{
	this->left_key = left;
	this->right_key = right;
	this->up_key = up;
	this->down_key = down;
	this->shot_key = shot;
}

void Ship::LaserRecharge(void* origin)
{
	Ship* ship = static_cast<Ship*>(origin);
	ship->laserAvailable = true;
}

void Ship::RemoveItem(void* origin)
{
	Ship* ship = static_cast<Ship*>(origin);
	ship->laserRechargeTime += 100;
}

