#include "Item.h"
#include <iostream>

//Item::Item(){}

Item::Item(Game* game, Actor* _origin, Vector2 start_pos, int direction)
	: Actor(game, "item_" , true)
	
	//, mLeftSpeed(200.0f)
//	, direction(direction)

{
	std::cout << "Item instantiated" << std::endl;
	this->SetPosition(start_pos);

	SpriteComponent* asc = new SpriteComponent(this);
	asc->SetTexture(game->GetTexture("Assets/Item.png"));
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

void Item::UpdateActor(int deltaTime)
{
	std::cout << "Item atualizado" << std::endl;
}

void Item::DropItem() {

}
