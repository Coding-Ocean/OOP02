#include "Game.h"
#include "framework.h"
#include "graphic.h"

bool Game::Initialize()
{
    window(1024, 768);
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
}

void Game::ProcessInput()
{
}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
    clear(60);
}
