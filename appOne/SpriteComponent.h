#pragma once
#include "Component.h"
class SpriteComponent :
    public Component
{
public:
	SpriteComponent(class Actor* owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw();
	virtual void SetImage(int img);

	int GetDrawOrder() const { return mDrawOrder; }
private:
    int mImg;
    int mDrawOrder;
};

