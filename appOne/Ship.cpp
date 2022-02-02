#include "Ship.h"
#include "Game.h"
#include "graphic.h"
#include "window.h"
#include "input.h"
#include "InputComponent.h"
#include "AnimSpriteComponent.h"
#include "ShipLaser.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mTimer(0.0f)
	,mInterval(0.1f)
{
    SetPosition(VECTOR2(width / 4, height / 2));
    SetScale(1.5f);

	auto ic = new InputComponent(this);
	ic->SetMoveSpeed(300);

    auto asc = new AnimSpriteComponent(this);
    asc->SetInterval(0.016f * 3);
    asc->AddImage(loadImage("Assets\\Ship01.png"));
    asc->AddImage(loadImage("Assets\\Ship02.png"));
    asc->AddImage(loadImage("Assets\\Ship03.png"));
    asc->AddImage(loadImage("Assets\\Ship04.png"));
}

void Ship::ActorInput()
{
	if (isPress(KEY_SPACE))
	{
		mTimer += delta;
		if (mTimer >= mInterval)
		{
			mTimer -= mInterval;
			auto laser = new ShipLaser(GetGame());
			//”­ŽËˆÊ’u‚ð‚¸‚ç‚·
			VECTOR2 pos = GetPosition()+VECTOR2(60,0);
			laser->SetPosition(pos);
			laser->SetDirection(VECTOR2(1,0));
		}
	}
	else
	{
		mTimer = mInterval;
	}
}
