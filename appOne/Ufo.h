#pragma once
#include "Actor.h"
class Ufo :
    public Actor
{
public:
    Ufo(class Game* game);
    ~Ufo();
    void UpdateActor() override;
    void SetTheta(float theta) { mTheta = theta; }
    void Damage();
    class RectComponent* GetRect() { return mRect; }
private:
    //“–‚½‚è”»’è
    class RectComponent* mRect;
    int mHP;
    //ã‰ºˆÚ“®—p
    class MoveComponent* mMove;
    float mTheta;
    //
    class AnimSpriteComponent* mAnimSprite;
    //ˆê’èŠÔ‚É”­Ë
    float mTimer;
    float mInterval;
};

