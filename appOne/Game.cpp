#include "Game.h"
#include "framework.h"
#include "graphic.h"
#include "window.h"
#include "SpriteComponent.h"
#include "Ufo.h"

bool Game::Initialize()
{
    window(1024, 768);

    Actor* a;
    a = new Ufo(this);
    a->SetPosition(VECTOR2(width / 3, height / 2));
    a = new Ufo(this);
    a->SetPosition(VECTOR2(width / 3*2, height / 2));
    a->SetScale(1.5f);

    a = new Actor(this);
    a->SetPosition(VECTOR2(100, height / 2));
    a->SetScale(1.5f);
    auto sc = new SpriteComponent(a);
    sc->SetImage(loadImage("Assets\\Ship01.png"));
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
    mActors.emplace_back(actor);
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
}

void Game::UpdateGame()
{
    for (auto actor : mActors)
    {
        actor->Update();
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
