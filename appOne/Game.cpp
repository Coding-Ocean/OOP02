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

    a = new Actor(this);
    auto bgsc = new BGSpriteComponent(a, 50);
    bgsc->setScrollSpeed(50);
    bgsc->addImage(loadImage("Assets\\FarBack01.png"));
    bgsc->addImage(loadImage("Assets\\FarBack02.png"));
    bgsc = new BGSpriteComponent(a, 60);
    bgsc->setScrollSpeed(100);
    bgsc->addImage(loadImage("Assets\\Stars.png"));
    bgsc->addImage(loadImage("Assets\\Stars.png"));

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

void Game::AddSprite(SpriteComponent* sprite)
{
    // ソート済み配列の挿入場所を探す
    // (自分より順番の大きい最初の要素を探す)
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (    ; iter != mSprites.end(); ++iter)
    {
        if (myDrawOrder < (*iter)->GetDrawOrder())
        {
            break;
        }
    }

    // 探し出した要素の前に自分を挿入
    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    // swapしてpop_backできない。swapしてしまうと順番が崩れるため
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}

void Game::ProcessInput()
{
}

void Game::UpdateGame()
{
    setDeltaTime();
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
