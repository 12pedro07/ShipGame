// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
#include "SDL/SDL_scancode.h"

class Ship : public Actor
{
	//as Ship will be controlled, it needs proper methods for it
public:
	Ship(class Game* game);
	void UpdateActor(float deltaTime) override;
	void Colided(Actor* target) override;
	void ProcessKeyboard(const uint8_t* state);
	void SetControls(SDL_Scancode left, SDL_Scancode right, SDL_Scancode up, SDL_Scancode down, SDL_Scancode shot);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }

	SDL_Scancode left_key;
	SDL_Scancode right_key;
	SDL_Scancode up_key;
	SDL_Scancode down_key;
	SDL_Scancode shot_key;

	int lives;

private:
	float mRightSpeed;
	float mDownSpeed;
	bool laserAvailable; // Booleano que diz se a nave pode ou nao atirar
	int laserRechargeTime; // Tempo para recarregar laser em ms
	static void LaserRecharge(void* origin); // callback que espera ate recarregar o laser
	static void RemoveItem(void* origin);
};