#pragma once
#include "SpriteComponent.h"
#include <vector>
class BGSpriteComponent :
    public SpriteComponent
{
public:
    BGSpriteComponent(class Actor* owner, int drawOrder=100);
    ~BGSpriteComponent();
    void addImage(int img);
    void Update() override;
    void Draw() override;
    void setScrollSpeed(float speed) { mScrollSpeed = speed; }
private:
    struct Bg {
        int img;
        float px;
    };
    std::vector<Bg>mBg;
    float mScrollSpeed;
};

