#include "console_utils.h"
#include <iostream>
#include <windows.h> // Necessário para manipular cores no terminal do Windows

void print(const std::string &text, ConsoleColor color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, static_cast<int>(color));
    std::cout << text << std::endl;
    SetConsoleTextAttribute(hConsole, static_cast<int>(ConsoleColor::DEFAULT)); // Resetar para cor padrão
}

template <typename T>
T getInput(const std::string &prompt, ConsoleColor color)
{
    print(prompt, color);
    T input;
    std::cin >> input;
    return input;
}

// Explicit template instantiations (necessário para evitar problemas de linkagem)
template int getInput<int>(const std::string &prompt, ConsoleColor color);
template float getInput<float>(const std::string &prompt, ConsoleColor color);
template double getInput<double>(const std::string &prompt, ConsoleColor color);
template std::string getInput<std::string>(const std::string &prompt, ConsoleColor color);