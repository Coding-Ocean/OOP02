#pragma once
#include "Component.h"
#include "VECTOR2.h"

class MoveComponent :
    public Component
{
public:
    MoveComponent(class Actor* owner, int order=100);
    void Update() override;
    void SetDirection(const VECTOR2& direction) { mDirection = direction; }
    void SetSpeed(float speed) { mSpeed = speed; }
    float GetSpeed() { return mSpeed; }
private:
    VECTOR2 mDirection;
    float mSpeed;
};

