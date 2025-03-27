#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include <string>

enum class ConsoleColor
{
    DEFAULT = 7,
    RED = 12,
    GREEN = 10,
    BLUE = 9,
    YELLOW = 14,
    CYAN = 11,
    MAGENTA = 13,
    WHITE = 15
};

// Exibe texto com uma cor específica
void print(const std::string &text, ConsoleColor color = ConsoleColor::DEFAULT);

// Recebe input genérico do usuário
template <typename T>
T getInput(const std::string &prompt, ConsoleColor color = ConsoleColor::DEFAULT);

#endif // CONSOLE_UTILS_H