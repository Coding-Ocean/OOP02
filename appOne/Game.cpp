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
    //‚±‚Ìactor‚ªmActors‚É‚ ‚é‚©’T‚·
    auto iter = std::find(mActors.begin(), mActors.end(), actor);
    if (iter != mActors.end())
    {
        //‚±‚ÌActor‚ÆƒPƒc‚ÌActor‚ð“ü‚ê‘Ö‚¦‚é(Á‹ŽŒãƒRƒs[ˆ—‚ð”ð‚¯‚é‚½‚ß)
        std::iter_swap(iter, mActors.end() - 1);
        mActors.pop_back();
    }
}

void Game::AddSprite(SpriteComponent* sprite)
{
    // ƒ\[ƒgÏ‚Ý”z—ñ‚Ì‘}“üêŠ‚ð’T‚·
    // (Ž©•ª‚æ‚è‡”Ô‚Ì‘å‚«‚¢Å‰‚Ì—v‘f‚ð’T‚·)
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (    ; iter != mSprites.end(); ++iter)
    {
        if (myDrawOrder < (*iter)->GetDrawOrder())
        {
            break;
        }
    }

    // ’T‚µo‚µ‚½—v‘f‚Ì‘O‚ÉŽ©•ª‚ð‘}“ü
    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
    // swap‚µ‚Äpop_back‚Å‚«‚È‚¢Bswap‚µ‚Ä‚µ‚Ü‚¤‚Æ‡”Ô‚ª•ö‚ê‚é‚½‚ß
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
