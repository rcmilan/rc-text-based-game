#include <iostream>
#include <windows.h>
#include "game.h"
#include "scenes/start_scene.cpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Configurar saída do console para UTF-8

    Game game;

    // Configurar a cena inicial
    game.setActiveScene(std::make_unique<StartScene>(&game));

    game.run();

    return 0;
}
