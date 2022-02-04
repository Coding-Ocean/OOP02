#include "Ufo.h"
#include "Game.h"
#include "MoveComponent.h"
#include "AnimSpriteComponent.h"
#include "RectComponent.h"
#include "graphic.h"
#include "window.h"
#include "Laser.h"
#include "VECTOR2.h"

Ufo::Ufo(Game* game)
	:Actor(game)
	, mTimer(0.0f)
	, mInterval(0.1f)
	, mTheta(0.0f)
	, mRect(nullptr)
	, mHP(0)
{
	mMove = new MoveComponent(this);
	mMove->SetSpeed(100);

	mAnimSprite = new AnimSpriteComponent(this);
	mAnimSprite->SetInterval(0.016f * 2);
	mAnimSprite->AddImage(loadImage("Assets\\Enemy01.png"));
	mAnimSprite->AddImage(loadImage("Assets\\Enemy02.png"));
	mAnimSprite->AddImage(loadImage("Assets\\Enemy03.png"));
	mAnimSprite->AddImage(loadImage("Assets\\Enemy04.png"));
	mAnimSprite->AddImage(loadImage("Assets\\Enemy05.png"));
	mAnimSprite->AddImage(loadImage("Assets\\Enemy06.png"));

	mRect = new RectComponent(this, 150);
	mRect->SetHalfW(15);
	mRect->SetHalfH(20);

	mHP = 20;

	GetGame()->AddUfo(this);
}

Ufo::~Ufo()
{
	GetGame()->RemoveUfo(this);
}

void Ufo::UpdateActor()
{
	//ã‰º‚É“®‚­
	mTheta += 0.017f;
	mMove->SetDirection(VECTOR2(0, sinf(mTheta)));

	//Laser”­ŽË
	mTimer += delta;
	if (mTimer > mInterval)
	{
		mTimer -= mInterval;
		auto laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetDirection(VECTOR2(-1,0));
	}
}

void Ufo::Damage()
{
	if (--mHP <= 0)
	{
		SetState(EDead);
	}
	mAnimSprite->StartFlash(0.032f,COLOR(255, 0, 0));
}
