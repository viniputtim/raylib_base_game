# include <raylib.h>
# include "loading.hpp"
# include "game.hpp"


Loading::Loading(Game *game) : Scene(game)
{

}


Loading::~Loading()
{

}


void Loading::check_events()
{

}


void Loading::update()
{

}


void Loading::draw()
{
    int x {(GetScreenWidth() - this->raylib_logo.width) / 2};
    int y {(GetScreenHeight() - this->raylib_logo.height) / 2};

    ClearBackground({RAYWHITE});
    DrawTexture(this->raylib_logo, x, y, WHITE);
}
