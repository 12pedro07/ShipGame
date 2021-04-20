// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <vector>
#include "Math.h"
#include <string>
class Actor//classe base de ator
{
public:
	enum State//possiveis estados do ator
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game, std::string name="unknown");//construtor e destrutor
	virtual ~Actor();

	// fun��o de atualiza��o, n�o sobrescreva
	void Update(float deltaTime);
	// fun��o para atualizar os componentes, n�o sobreescreva
	void UpdateComponents(float deltaTime);
	// atualiza��o espec�fica do ator, deve ser sobreescrita
	virtual void UpdateActor(float deltaTime);
	// fun��o que dita o que ocorre em caso de colisao
	virtual void Colided(Actor* target);

	// Getters/setters
	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }

	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	class Game* GetGame() { return mGame; }


	// insere e remove componentes
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
//vari�veis do ator
private:
	// estado
	State mState;

	// coordenadas do ator, assim como sua escala e par�metro para rota��o
	Vector2 mPosition;
	float mScale;
	float mRotation;

	//vetor de componentes
	std::vector<class Component*> mComponents;
	class Game* mGame;

public:
	// debug variables
	std::string name;
};
