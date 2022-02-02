#include "Ufo.h"
#include "MoveComponent.h"
#include "AnimSpriteComponent.h"
#include "graphic.h"
#include "window.h"
#include "Laser.h"
#include "VECTOR2.h"

Ufo::Ufo(Game* game)
	:Actor(game)
	, mTimer(0.0f)
	, mInterval(0.1f)
	, mTheta(0.0f)
{
	mMc = new MoveComponent(this);
	mMc->SetSpeed(100);

	auto asc = new AnimSpriteComponent(this);
	asc->SetInterval(0.016f * 2);
	asc->AddImage(loadImage("Assets\\Enemy01.png"));
	asc->AddImage(loadImage("Assets\\Enemy02.png"));
	asc->AddImage(loadImage("Assets\\Enemy03.png"));
	asc->AddImage(loadImage("Assets\\Enemy04.png"));
	asc->AddImage(loadImage("Assets\\Enemy05.png"));
	asc->AddImage(loadImage("Assets\\Enemy06.png"));
}

void Ufo::UpdateActor()
{
	mTheta += 0.017f;
	mMc->SetDirection(VECTOR2(0, sin(mTheta)));

	mTimer += delta;
	if (mTimer > mInterval)
	{
		mTimer -= mInterval;
		auto laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetDirection(VECTOR2(-1,0));
	}
}
