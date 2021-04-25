#include "Item.h"
#include <iostream>

//Item::Item(){}

Item::Item(Game* game, Actor* origin, Vector2 start_pos, int direction)
	: Actor(game, "item_" + origin->name , true)
	
	, mLeftSpeed(200.0f)
	, direction(direction)

{
	
	this->SetPosition(start_pos);
	SpriteComponent* asc = new SpriteComponent(this);
	auto texture = game->GetTexture("Assets/ruby.png");
	
	asc->SetTexture(texture);
	this->SetScale(0.5f);
}

Item::~Item()
{

}


//
void Item::TwoShots() {

}

void Item::IncreaseVelocity()
{


}

void Item::UpdateActor(float deltaTime)
{
	Vector2 pos = GetPosition();
	pos.x += mLeftSpeed * deltaTime * direction;
	SetPosition(pos);
	if (pos.x > 1024 || pos.x < 0) {
		this->SetState(EDead);
		return;
	}
	this->GetGame()->CheckColision(this);


}

void Item::DropItem() {

}

void Item::Colided(Actor* target)
{
	Item::SetState(EDead);
}
