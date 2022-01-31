#include "Ufo.h"
#include "graphic.h"

Ufo::Ufo(Game* game)
	:Actor(game)
{
	//�f�o�b�N�p�R�[�h
	mImg = loadImage("Assets\\Enemy01.png");
}

void Ufo::UpdateActor()
{
	//�f�o�b�N�p�R�[�h
	VECTOR2 p = GetPosition();
	float a = GetRotation();
	float s = GetScale();
	rectMode(CENTER);
	image(mImg, p.x, p.y, a, s);
}
