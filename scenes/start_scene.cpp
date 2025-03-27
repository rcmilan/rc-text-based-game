#include "scene.cpp"
#include <iostream>

class StartScene : public Scene
{
public:
    StartScene() : Scene("StartScene") {}

    void initialize() override
    {
        print("Bem-vindo ao jogo!", ConsoleColor::GREEN);
        print("Digite seu nome:", ConsoleColor::CYAN);
    
        std::string nome = getInput<std::string>("Seu nome: ", ConsoleColor::YELLOW);
        print("Olá, " + nome + "!", ConsoleColor::MAGENTA);    
    }

    void update() override
    {
        // Aguarda o jogador pressionar Enter
        if (std::cin.get() == '\n')
        {
            std::cout << "Iniciando o jogo..." << std::endl;
        }
    }

    void render() override
    {
        // Renderiza elementos visuais da tela inicial (se necessário)
        std::cout << "Renderizando a tela inicial..." << std::endl;
    }

    ~StartScene() override {}
};