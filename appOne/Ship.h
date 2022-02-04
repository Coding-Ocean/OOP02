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
    //�����蔻��
    class RectComponent* mRect;
    int mHP;
    //�L�[��������Ă���ԁA��莞�Ԃɔ���
    float mTimer;
    float mInterval;
};

