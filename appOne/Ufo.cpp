#include "Ufo.h"
#include "SpriteComponent.h"
#include "graphic.h"

Ufo::Ufo(Game* game)
	:Actor(game)
{
	auto sc = new SpriteComponent(this);
	sc->SetImage(loadImage("Assets\\Enemy01.png"));
}
