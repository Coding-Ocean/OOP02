#pragma once
#include "Actor.h"
class Ship :
    public Actor
{
public:
    Ship(class Game* game);
    void ActorInput() override;
private:
    float mTimer;
    float mInterval;
};

