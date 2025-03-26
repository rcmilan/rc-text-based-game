#include <iostream>
#include <windows.h> // Necessário para configurar o console no Windows
#include "utils/json_utils.h"
#include "scenes/start_scene.cpp" // Inclui a StartScene

int main()
{
    // Configurar saída do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Instanciar e usar a StartScene
    StartScene startScene;
    startScene.initialize();
    startScene.render();
    startScene.update();

    return 0;
}
