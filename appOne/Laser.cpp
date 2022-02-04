#include "Laser.h"
#include "graphic.h"
#include "window.h"
#include "Game.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "RectComponent.h"
#include "Ship.h"

Laser::Laser(Game* game)
	:Actor(game)
{
	mMove = new MoveComponent(this);
	mMove->SetSpeed(600);

	auto sc = new SpriteComponent(this, 50);
	sc->SetImage(loadImage("Assets\\LaserG.png"));

	mRect = new RectComponent(this, 110);
	mRect->SetHalfW(14);
	mRect->SetHalfH(6);
}

void Laser::UpdateActor()
{
	//ウィンドウの外に出たらDead
	VECTOR2 pos = GetPosition();
	if (pos.x < -50 || pos.x > width + 50)
	{
		SetState(EDead);
	}
	else 
	{
		//Shipとの衝突判定
		if(auto ship = GetGame()->GetShip())
		{
			if (Intersect(mRect, ship->GetRect()))
			{
				SetState(EDead);
				ship->Damage();
			}
		}
	}
}

void Laser::SetSpeed(float speed)
{
	mMove->SetSpeed(speed);
}

void Laser::SetDirection(const VECTOR2& direction)
{
	mMove->SetDirection(direction);
}
