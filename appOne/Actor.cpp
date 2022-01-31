#include "Actor.h"

Actor::Actor(Game* game)
	: mGame(game)
	, mState(EActive)
{
}

Actor::~Actor()
{
}

void Actor::Update()
{
	if (mState == EActive)
	{
		UpdateActor();
	}
}
