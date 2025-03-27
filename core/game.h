#ifndef GAME_H
#define GAME_H

#include <memory>
#include "scenes/scene.h"
#include "utils/console_utils.h"

class Game
{
private:
    std::unique_ptr<Scene> activeScene;
    bool isRunning;

public:
    Game();
    void setActiveScene(std::unique_ptr<Scene> scene);
    void run();
    void stop();
    void exitGame();
};

#endif // GAME_H