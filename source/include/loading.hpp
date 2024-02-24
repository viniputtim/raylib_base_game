# ifndef LOADING_HPP
# define LOADING_HPP

# include <raylib.h>
# include "scene.hpp"


class Loading : public Scene
{
private:
    Texture2D raylib_logo {LoadTexture("../assets/graphics/raylib_logo.png")};

public:
    Loading(Game *game);
    ~Loading();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
