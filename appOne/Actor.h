#pragma once
#include "VECTOR2.h"
#include <vector>
class Actor
{
public:
	enum State
	{
		EActive, EPause, EDead
	};

	Actor(class Game* game);
	virtual ~Actor();
	
	void ProcessInput();
	virtual void ActorInput() {}

	void Update();
	virtual void UpdateActor() {}

	//Getters,Setters
	State GetState() const { return mState; }
	void SetState(State state) { mState = state; }

	const VECTOR2& GetPosition() const { return mPosition; }
	void SetPosition(const VECTOR2& pos) { mPosition = pos; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale; }

	class Game* GetGame() { return mGame; }

	void AddComponent(class Component*);
	void RemoveComponent(class Component*);
private:
	//Actor�̏��
	State mState;
	//�g�����X�t�H�[��
	VECTOR2 mPosition;
	float mRotation;
	float mScale;
	//Game�N���X��public�����o�ɃA�N�Z�X����|�C���^
	class Game* mGame;
	//component�z��
	std::vector<class Component*> mComponents;
};

