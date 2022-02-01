#pragma once
#include <vector>
#include "VECTOR2.h"
class Game
{
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	std::vector<class Actor*>mActors;
	std::vector<class SpriteComponent*>mSprites;

	// Update���t���b�O
	bool mUpdatingActors;
	std::vector<class Actor*> mPendingActors;

	//����Game�ŗL�̋L�q
public:
	const VECTOR2& GetUfoPos();
	class Ufo* mUfo;
};

