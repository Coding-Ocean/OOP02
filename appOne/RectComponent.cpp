#include "RectComponent.h"
#include "Actor.h"

RectComponent::RectComponent(Actor* owner, int order)
	:Component(owner, order)
	, mHalfW(0.0f)
	, mHalfH(0.0f)
{
}

const VECTOR2& RectComponent::GetCenter()const
{
	return mOwner->GetPosition();
}

bool Intersect(const RectComponent* a, const RectComponent* b)
{
	VECTOR2 diff = (a->GetCenter() - b->GetCenter());
	float ww = a->GetHalfW() + b->GetHalfW();
	if (abs(diff.x) < ww)
	{
		float hh = a->GetHalfH() + b->GetHalfH();
		if (abs(diff.y) < hh)
		{
			return true;
		}
	}
	return false;
}
