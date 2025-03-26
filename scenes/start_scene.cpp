#include "scene.cpp"
#include <iostream>

class StartScene : public Scene
{
public:
    StartScene() : Scene("StartScene") {}

    void initialize() override
    {
        std::cout << "Bem-vindo ao jogo!" << std::endl;
        std::cout << "Pressione Enter para começar..." << std::endl;
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