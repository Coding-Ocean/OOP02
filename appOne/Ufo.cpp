#include "Ufo.h"
#include "graphic.h"

Ufo::Ufo(Game* game)
	:Actor(game)
{
	//デバック用コード
	mImg = loadImage("Assets\\Enemy01.png");
}

void Ufo::UpdateActor()
{
	//デバック用コード
	VECTOR2 p = GetPosition();
	float a = GetRotation();
	float s = GetScale();
	rectMode(CENTER);
	image(mImg, p.x, p.y, a, s);
}
