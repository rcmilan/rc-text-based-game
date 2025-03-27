#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "../utils/console_utils.h"
#include "../core/game.h"

class Game; // Forward declaration

class Scene
{
protected:
    Game* game; // Referência ao jogo

public:
    std::string sceneName;

    Scene(const std::string &name, Game* gameInstance) : sceneName(name), game(gameInstance) {}

    virtual void initialize()
    {
        // Initialization code for the scene
    }

    virtual void update()
    {
        // Update logic for the scene
    }

    virtual void render()
    {
        // Rendering code for the scene
    }

    virtual ~Scene() {}
};

#endif // SCENE_H