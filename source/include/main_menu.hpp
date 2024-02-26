# ifndef MAIN_MENU_HPP
# define MAIN_MENU_HPP

# include <raylib.h>
# include "scene.hpp"


class MainMenu : public Scene
{
private:
    const char *title_text {"Game"};
    int title_font_size {80};
    Color title_color {BLACK};
    const char *button_text {"Play"};
    int button_font_size {40};
    int spacing {2};
    Color button_color {BLACK};
    Color button_hover_color {DARKGRAY};

    Vector2 calculate_title_position();
    Vector2 get_title_size();
    bool is_mouse_hover_button();
    Vector2 calculate_button_position();
    Vector2 get_button_size();

public:
    MainMenu(Game *game);
    ~MainMenu();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
