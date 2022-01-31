#include "SpriteComponent.h"
#include "Actor.h"
#include "graphic.h"

SpriteComponent::SpriteComponent(Actor* actor)
	:Component(actor)
{
	mImg = loadImage("Assets\\Enemy01.png");
}

void SpriteComponent::Update()
{
	//デバック用コード
	VECTOR2 p = mOwner->GetPosition();
	float a = mOwner->GetRotation();
	a += 0.017f;
	mOwner->SetRotation(a);
	float s = mOwner->GetScale();
	rectMode(CENTER);
	image(mImg, p.x, p.y, a, s);
}

