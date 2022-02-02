#pragma once
#include "Actor.h"
class Ufo :
    public Actor
{
public:
    Ufo(class Game* game);
    void UpdateActor() override;
    void SetTheta(float theta) { mTheta = theta; }
private:
    float mTimer;
    float mInterval;
    class MoveComponent* mMc;
    float mTheta;
};

