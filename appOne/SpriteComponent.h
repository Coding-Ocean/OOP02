#pragma once
#include "Component.h"
class SpriteComponent :
    public Component
{
public:
    SpriteComponent(class Actor*);
    void Update() override;
private:
    //�f�o�b�O�p�R�[�h
    int mImg;
};

