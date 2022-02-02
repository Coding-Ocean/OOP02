#include "ShipLaser.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "graphic.h"
#include "window.h"
#include "Game.h"

ShipLaser::ShipLaser(Game* game)
	:Actor(game)
{
	mMc = new MoveComponent(this);
	mMc->SetSpeed(600);

	auto sc = new SpriteComponent(this, 50);
	sc->SetImage(loadImage("Assets\\Laser.png"));
}

void ShipLaser::UpdateActor()
{
	//ウィンドウの外に出たらDead
	VECTOR2 pos = GetPosition();
	if (pos.x < -50 || pos.x > width + 50)
	{
		SetState(EDead);
	}
}

void ShipLaser::SetSpeed(float speed)
{
	mMc->SetSpeed(speed);
}

void ShipLaser::SetDirection(const VECTOR2& direction)
{
	mMc->SetDirection(direction);
}
