# ifndef LELVEL_ONE_HPP
# define LELVEL_ONE_HPP


# include <raylib.h>
# include "game.hpp"
# include "scene.hpp"


class LevelOne : public Scene
{
private:


public:
    LevelOne(Game *game);
    ~LevelOne();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
