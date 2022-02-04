#include "Game.h"
#include "framework.h"
#include "graphic.h"
#include "window.h"
#include "BGSpriteComponent.h"
#include "AnimSpriteComponent.h"
#include "Ufo.h"
#include "Ship.h"

bool Game::Initialize()
{
    window(1024, 768);

    new Ship(this);

    auto ufo = new Ufo(this);
    ufo->SetPosition(VECTOR2(width / 4 * 3, height/2 - 100));

    ufo = new Ufo(this);
    ufo->SetPosition(VECTOR2(width / 4 * 3, height/2 + 100));
    ufo->SetTheta(3.14f);

    ufo = new Ufo(this);
    ufo->SetPosition(VECTOR2(width / 4 * 3, height / 2 - 100));
    ufo->SetTheta(3.14f);

    ufo = new Ufo(this);
    ufo->SetPosition(VECTOR2(width / 4 * 3, height / 2 + 100));

    Actor* a;
    a = new Actor(this);
    auto bg = new BGSpriteComponent(a, 50);
    bg->SetScrollSpeed(100);
    bg->SetImage(loadImage("Assets\\FarBack01.png"));
    bg->SetImage(loadImage("Assets\\FarBack02.png"));
    bg = new BGSpriteComponent(a, 60);
    bg->SetScrollSpeed(200);
    bg->SetImage(loadImage("Assets\\Stars.png"));
    bg->SetImage(loadImage("Assets\\Stars.png"));

    initDeltaTime();
    return true;
}

void Game::RunLoop()
{
    while (notQuit)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::Shutdown()
{
    while (!mActors.empty())
    {
        delete mActors.back();
    }
}

void Game::AddActor(Actor* actor)
{
    //Update���Ȃ�A�ǉ���Update��ɉ�������
    if (mUpdatingActors)
    {
        mPendingActors.emplace_back(actor);
    }
    else
    {
        mActors.emplace_back(actor);
    }
}

void Game::RemoveActor(Actor* actor)
{
    //����actor��mActors�ɂ��邩�T��
    auto iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end())
    {
        //����Actor�ƃP�c��Actor�����ւ���(������R�s�[����������邽��)
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}

void Game::AddSprite(SpriteComponent* sprite)
{
    // �\�[�g�ςݔz��̑}���ꏊ��T��
    // (������菇�Ԃ̑傫���ŏ��̗v�f��T��)
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (    ; iter != mSprites.end(); ++iter)
    {
        if (myDrawOrder < (*iter)->GetDrawOrder())
        {
            break;
        }
    }

    // �T���o�����v�f�̑O�Ɏ�����}��
    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    // swap����pop_back�ł��Ȃ��Bswap���Ă��܂��Ə��Ԃ�����邽��
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}

void Game::ProcessInput()
{
    mUpdatingActors = true;
    for (auto actor : mActors)
    {
        actor->ProcessInput();
    }
    mUpdatingActors = false;
}

void Game::UpdateGame()
{
    setDeltaTime();

    // mActors�X�V(�X�V����new���ꂽActor��mPendingActors�ɒǉ������)
    mUpdatingActors = true;
    for (auto actor : mActors)
    {
        actor->Update();
    }
    mUpdatingActors = false;

    // �ǉ�����������Actor��mActors�ɒǉ�����
    for (auto pending : mPendingActors)
    {
        mActors.emplace_back(pending);
    }
    mPendingActors.clear();

    // Dead��Ԃ�Actor�𒼉���deadActors�ɒ��o����
    std::vector<Actor*> deadActors;
    for (auto actor : mActors)
    {
        if (actor->GetState() == Actor::EDead)
        {
            deadActors.emplace_back(actor);
        }
    }
    // deadActors����������(mActors�������菜�����)
    for (auto actor : deadActors)
    {
        delete actor;
    }
}

void Game::GenerateOutput()
{
    clear(60);
    for (auto sprite : mSprites)
    {
        sprite->Draw();
    }
}

//���̃Q�[���ɌŗL�̃��W�b�N
void Game::AddUfo(Ufo* ufo)
{
    mUfos.emplace_back(ufo);
}

void Game::RemoveUfo(Ufo* ufo)
{
    auto iter = std::find(mUfos.begin(), mUfos.end(), ufo);
    if (iter != mUfos.end())
    {
        std::iter_swap(iter, mUfos.end() - 1);
        mUfos.pop_back();
    }
}
