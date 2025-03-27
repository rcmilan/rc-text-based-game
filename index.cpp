#include <iostream>
#include <windows.h>
#include "game.h"
#include "scenes/start_scene.cpp"

int main()
{
    // Configurar saída do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Criar o jogo
    Game game;

    // Configurar a cena inicial
    game.setActiveScene(std::make_unique<StartScene>(&game));

    // Executar o game loop
    game.run();

    return 0;
}
