#include "BGSpriteComponent.h"
#include "Actor.h"
#include "graphic.h"
#include "window.h"

BGSpriteComponent::BGSpriteComponent(Actor* owner, int drawOrder)
	: SpriteComponent(owner,drawOrder)
	, mScrollSpeed(0.0f)
{
}

BGSpriteComponent::~BGSpriteComponent()
{
}

void BGSpriteComponent::addImage(int img)
{
	Bg bg;
	bg.img = img;
	bg.px = mBg.size() * width;
	mBg.emplace_back(bg);
}

void BGSpriteComponent::Update()
{
	for (int i = 0; i < mBg.size(); i++) 
	{
		mBg[i].px -= mScrollSpeed * delta;
		if (mBg[i].px < -width) {
			mBg[i].px += width * 2;
		}
	}
}

void BGSpriteComponent::Draw()
{
	rectMode(CORNER);
	for (int i = 0; i < mBg.size(); i++)
	{
		image(mBg[i].img, mBg[i].px, 0);
	}
}

