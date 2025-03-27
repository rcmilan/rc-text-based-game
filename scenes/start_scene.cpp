#include "scene.h"
#include <iostream>

class StartScene : public Scene
{
private:
    bool isComplete;

public:
    StartScene(Game* gameInstance) : Scene("StartScene", gameInstance), isComplete(false) {}

    void initialize() override
    {
        print("Bem-vindo ao jogo!", ConsoleColor::GREEN);
        print("Digite seu nome:", ConsoleColor::CYAN);

        std::string nome = getInput<std::string>("Seu nome: ", ConsoleColor::YELLOW);
        print("Olá, " + nome + "!", ConsoleColor::MAGENTA);
    }

    void update() override
    {
        std::string input = getInput<std::string>("Pressione Enter para continuar ou digite 'sair' para encerrar o jogo...", ConsoleColor::YELLOW);

        if (input == "sair")
        {
            game->exitGame();
        }
        else
        {
            isComplete = true;
        }
    }

    void render() override
    {
        print("Renderizando a tela inicial...", ConsoleColor::BLUE);
    }

    bool completed() const
    {
        return isComplete;
    }
};