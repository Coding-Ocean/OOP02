#pragma once
#include "Component.h"
class SpriteComponent :
    public Component
{
public:
    SpriteComponent(class Actor*);
    void Update() override;
private:
    //デバッグ用コード
    int mImg;
};

