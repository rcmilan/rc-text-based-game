#include <iostream>
#include <windows.h> // Necessário para configurar o console no Windows
#include "utils/json_utils.h"

int main()
{
    // Configurar saída do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);

    std::string lang = "pt";
    std::cout << getFileContent("begin", lang) << std::endl;
    return 0;
}
