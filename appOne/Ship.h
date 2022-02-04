#pragma once
#include "Actor.h"
class Ship :
    public Actor
{
public:
    Ship(class Game* game);
    ~Ship();
    void ActorInput() override;
    void Damage();
    class RectComponent* GetRect()const { return mRect; }
private:
    class AnimSpriteComponent* mAnimSprite;
    //“–‚½‚è”»’è
    class RectComponent* mRect;
    int mHP;
    //ƒL[‚ª‰Ÿ‚³‚ê‚Ä‚¢‚éŠÔAˆê’èŠÔ‚É”­Ë
    float mTimer;
    float mInterval;
};

