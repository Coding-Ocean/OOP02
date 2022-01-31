#include "Game.h"
#include "framework.h"
#include "graphic.h"
#include "Ufo.h"

bool Game::Initialize()
{
    window(1024, 768);

    Actor* a;
    a = new Ufo(this);
    a->SetPosition(VECTOR2(width / 3, height / 2));
    a = new Ufo(this);
    a->SetPosition(VECTOR2(width / 3*2, height / 2));

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
    //このactorがmActorsにあるか探す
    auto iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end())
    {
        //このActorとケツのActorを入れ替える(消去後コピー処理を避けるため)
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}

void Game::ProcessInput()
{
}

void Game::UpdateGame()
{
    clear(60);
    for (auto actor : mActors)
    {
        actor->Update();
    }
}

void Game::GenerateOutput()
{
}
