#include <memory>
#include "scenes/scene.h"
#include "utils/console_utils.h"
#include "game.h"

Game::Game() : isRunning(true) {}

void Game::setActiveScene(std::unique_ptr<Scene> scene)
{
    activeScene = std::move(scene);
}

void Game::run()
{
    while (isRunning)
    {
        if (activeScene)
        {
            activeScene->initialize();
            activeScene->render();

            // Aguarda input do jogador e atualiza a cena
            activeScene->update();
        }
        else
        {
            print("Nenhuma cena ativa. Encerrando o jogo.", ConsoleColor::RED);
            stop();
        }
    }
}

void Game::stop()
{
    isRunning = false;
}

void Game::exitGame()
{
    print("O jogo foi encerrado pela cena.", ConsoleColor::RED);
    stop();
}