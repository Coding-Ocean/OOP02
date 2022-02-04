#pragma once
#include "SpriteComponent.h"
#include <vector>
#include "VECTOR2.h"
class BGSpriteComponent :
    public SpriteComponent
{
public:
    BGSpriteComponent(class Actor* owner, int drawOrder=100);
    ~BGSpriteComponent();
    void SetImage(int img) override;
    void Update() override;
    void Draw() override;
    void SetScrollSpeed(float speed) { mScrollSpeed = speed; }
private:
    struct Back {
        int img;
        VECTOR2 pos;
    };
    std::vector<Back>mBack;
    float mScrollSpeed;
};

