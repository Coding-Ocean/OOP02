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
    //�����蔻��
    class RectComponent* mRect;
    int mHP;
    //�㉺�ړ��p
    class MoveComponent* mMove;
    float mTheta;
    //
    class AnimSpriteComponent* mAnimSprite;
    //��莞�Ԃɔ���
    float mTimer;
    float mInterval;
};

