#include "Ufo.h"
#include "SpriteComponent.h"

Ufo::Ufo(Game* game)
	:Actor(game)
{
	SetScale(2.0f);

	new SpriteComponent(this);
}
