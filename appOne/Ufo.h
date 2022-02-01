#pragma once
#include "Actor.h"
class Ufo :
    public Actor
{
public:
    Ufo(class Game* game);
    void UpdateActor() override;
private:
    float mTimer;
    float mInterval;
};

