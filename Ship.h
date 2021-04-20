// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"
class Ship : public Actor
{
	//as Ship will be controlled, it needs proper methods for it
public:
	Ship(class Game* game);
	void UpdateActor(float deltaTime) override;
	void Colided(Actor* target) override;
	void ProcessKeyboard(const uint8_t* state);
	float GetRightSpeed() const { return mRightSpeed; }
	float GetDownSpeed() const { return mDownSpeed; }
private:
	float mRightSpeed;
	float mDownSpeed;
	bool laserAvailable; // Booleano que diz se a nave pode ou nao atirar
	int laserRechargeTime; // Tempo para recarregar laser em ms
	static void LaserRecharge(void* origin); // callback que espera ate recarregar o laser

};