#include <string>

class Scene
{
public:
    std::string sceneName;

    Scene(const std::string &name) : sceneName(name) {}

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