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
    //Update中なら、追加をUpdate後に延期する
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

    // mActors更新(更新中にnewされたActorはmPendingActorsに追加される)
    mUpdatingActors = true;
    for (auto actor : mActors)
    {
        actor->Update();
    }
    mUpdatingActors = false;

    // 追加を延期したActorをmActorsに追加する
    for (auto pending : mPendingActors)
    {
        mActors.emplace_back(pending);
    }
    mPendingActors.clear();

    // Dead状態のActorを直下のdeadActorsに抽出する
    std::vector<Actor*> deadActors;
    for (auto actor : mActors)
    {
        if (actor->GetState() == Actor::EDead)
        {
            deadActors.emplace_back(actor);
        }
    }
    // deadActorsを消去する(mActorsからも取り除かれる)
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

//このゲームに固有のロジック
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
