#pragma once
class Component
{
public:
	// �R���X�g���N�^
	// (updateOder�����������A��ɍX�V�����)
	Component(class Actor* owner, int updateOrder = 100);
	// �f�X�g���N�^
	virtual ~Component();
	// ���̃R���|�[�l���g�̓��͏���
	virtual void ProcessInput(){}
	// ���̃R���|�[�l���g�̍X�V����
	virtual void Update(){}

	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	// ����Component�����L����Actor
	class Actor* mOwner;
	// �X�V�̏���
	int mUpdateOrder;
};

