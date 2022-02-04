#pragma once
#include "Component.h"
#include "VECTOR2.h"
class RectComponent :
    public Component
{
public:
    RectComponent(class Actor* owner, int order);
    const VECTOR2& GetCenter()const;
    void SetHalfW(float w) { mHalfW = w; }
    void SetHalfH(float h) { mHalfH = h; }
    float GetHalfW() const{ return mHalfW; }
    float GetHalfH() const{ return mHalfH; }
private:
    float mHalfW;
    float mHalfH;
};

bool Intersect(const RectComponent* a, const RectComponent* b);
