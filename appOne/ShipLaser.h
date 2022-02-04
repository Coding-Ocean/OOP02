#pragma once
#include "Actor.h"
class ShipLaser :
    public Actor
{
public:
    ShipLaser(class Game*);
    void UpdateActor() override;
    void SetSpeed(float speed);
    void SetDirection(const VECTOR2& direction);
private:
    class MoveComponent* mMove;
    class RectComponent* mRect;
};

