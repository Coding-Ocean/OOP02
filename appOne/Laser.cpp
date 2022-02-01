#include "Laser.h"
#include "SpriteComponent.h"
#include "graphic.h"
#include "window.h"
#include "Game.h"

Laser::Laser(Game* game)
	:Actor(game)
	,mForwardSpeed(600)
	,mForwardVec(1)
{
	auto sc = new SpriteComponent(this, 50);
	sc->SetImage(loadImage("Assets\\Laser.png"));
}

void Laser::UpdateActor()
{
	VECTOR2 pos = GetPosition();
	pos.x += mForwardVec * mForwardSpeed * delta;
	SetPosition(pos);
	if (pos.x < -50 || pos.x > width+50)
	{
		SetState(EDead);
	}
}
