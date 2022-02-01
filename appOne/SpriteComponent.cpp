#include "SpriteComponent.h"
#include "Actor.h"
#include "graphic.h"
#include "Game.h"

SpriteComponent::SpriteComponent(class Actor* owner, int drawOrder)
	:Component(owner)
	, mImg(-1)
	, mDrawOrder(drawOrder)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::SetImage(int img)
{
	mImg = img;
}

void SpriteComponent::Draw()
{
	VECTOR2 p = mOwner->GetPosition();
	float a = mOwner->GetRotation();
	float s = mOwner->GetScale();
	rectMode(CENTER);
	image(mImg, p.x, p.y, a, s);
}

