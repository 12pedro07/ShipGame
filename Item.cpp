#include "Item.h"

Item::Item(Game* game, Actor* _origin, Vector2 start_pos, int direction)
	: Actor(game, "laser_", true)
	
	, mLeftSpeed(200.0f)
	, direction(direction)

{
	this->SetPosition(start_pos);

	SpriteComponent* asc = new SpriteComponent(this);
	asc->SetTexture(game->GetTexture("Assets/Item.png"));
}


//
//void Item::TwoShots() {
//
//}
//
//void Item::IncreaseVelocity()
//{
//
//
//}
//
//void Item::DropItem() {
//
//}
