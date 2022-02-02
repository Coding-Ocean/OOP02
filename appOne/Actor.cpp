#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(Game* game)
	: mGame(game)
	, mState(EActive)
	, mRotation(0.0f)
	, mScale(1.0f)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);

	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::ProcessInput()
{
	if (mState == EActive)
	{
		for (auto comp : mComponents)
		{
			comp->ProcessInput();
		}

		ActorInput();
	}
}

void Actor::Update()
{
	if (mState == EActive)
	{
		for (auto component : mComponents)
		{
			component->Update();
		}

		UpdateActor();
	}
}

void Actor::AddComponent(Component* component)
{
	// �\�[�g�ςݔz��̑}���ꏊ��T��
	// (������菇�Ԃ̑傫���ŏ��̗v�f��T��)
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (  ; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	// �T���o�����v�f�̑O�Ɏ�����}��
	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}
