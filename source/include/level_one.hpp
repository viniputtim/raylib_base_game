# ifndef LELVEL_ONE_HPP
# define LELVEL_ONE_HPP

# include <raylib.h>
# include "scene.hpp"


class LevelOne : public Scene
{
private:
    Texture2D raylib_logo {LoadTexture("../assets/graphics/raylib_logo.png")};

public:
    LevelOne(Game *game);
    ~LevelOne();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
