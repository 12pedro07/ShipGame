#pragma once
#include "Actor.h"
#include "SpriteComponent.h"
#include "Game.h"

class Item : public Actor
{
private:
    float mLeftSpeed; // Velocidade à esquerda
    int direction;
    //Actor* origin;

public:
    

    Item(class Game* game, Actor* origin, Vector2 start_pos, int direction = -1);
    
    virtual ~Item();

    //Atualiza o Actor
    void UpdateActor(float deltaTime) override;
    float GetLeftSpeed() const { return mLeftSpeed; };
    void DropItem();

    //Habilidades especiais
    void TwoShots();
    void IncreaseVelocity();
    void Colided(Actor* target) override;
    


};

