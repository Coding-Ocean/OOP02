#pragma once
#include "Actor.h"
class Laser :
    public Actor
{
public:
    Laser(class Game*);
    void UpdateActor() override;
    void SetSpeed(float speed);
    void SetDirection(const VECTOR2& direction);
private:
    class MoveComponent* mMove;
    class RectComponent* mRect;
};

