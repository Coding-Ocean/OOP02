#pragma once
#include "Actor.h"
class Ufo :
    public Actor
{
public:
    Ufo(class Game* game);
    void UpdateActor() override;
private:

    //�f�o�b�O�p�R�[�h
    int mImg;
};

