#include "ShipLaser.h"
#include "graphic.h"
#include "window.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "RectComponent.h"
#include "Game.h"
#include "Ufo.h"

ShipLaser::ShipLaser(Game* game)
	:Actor(game)
{
	mMove = new MoveComponent(this);
	mMove->SetSpeed(600);

	auto sc = new SpriteComponent(this, 50);
	sc->SetImage(loadImage("Assets\\Laser.png"));

	mRect = new RectComponent(this, 110);
	mRect->SetHalfW(14);
	mRect->SetHalfH(6);
}

void ShipLaser::UpdateActor()
{
	//ウィンドウの外に出たらDead
	VECTOR2 pos = GetPosition();
	if (pos.x < -50 || pos.x > width + 50)
	{
		SetState(EDead);
	}
	else{
		//衝突判定
		for (auto ufo : GetGame()->GetUfos()) {
			if (Intersect(mRect, ufo->GetRect()))
			{
				SetState(EDead);
				ufo->Damage();
			}
		}
	}
}

void ShipLaser::SetSpeed(float speed)
{
	mMove->SetSpeed(speed);
}

void ShipLaser::SetDirection(const VECTOR2& direction)
{
	mMove->SetDirection(direction);
}
