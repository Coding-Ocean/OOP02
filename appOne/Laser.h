#pragma once
#include "Actor.h"
class Laser :
    public Actor
{
public:
    Laser(class Game*);
    void UpdateActor() override;
    void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
    void SetForwardVec(float vec) { mForwardVec = vec; }
private:
    float mForwardSpeed;
    float mForwardVec;
};

