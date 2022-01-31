#include "Actor.h"
#include "Game.h"

Actor::Actor(Game* game)
	: mGame(game)
	, mState(EActive)
	, mRotation(0.0f)
	, mScale(1.0f)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
}

void Actor::Update()
{
	if (mState == EActive)
	{
		UpdateActor();
	}
}
