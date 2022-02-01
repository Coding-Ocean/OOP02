#include "Ufo.h"
#include "AnimSpriteComponent.h"
#include "graphic.h"

Ufo::Ufo(Game* game)
	:Actor(game)
{
	auto asc = new AnimSpriteComponent(this);
	asc->SetInterval(0.016 * 2);
	asc->AddImage(loadImage("Assets\\Enemy01.png"));
	asc->AddImage(loadImage("Assets\\Enemy02.png"));
	asc->AddImage(loadImage("Assets\\Enemy03.png"));
	asc->AddImage(loadImage("Assets\\Enemy04.png"));
	asc->AddImage(loadImage("Assets\\Enemy05.png"));
	asc->AddImage(loadImage("Assets\\Enemy06.png"));
}
