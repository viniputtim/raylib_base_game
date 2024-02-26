# include <raylib.h>
# include "game.hpp"
# include "main_menu.hpp"
# include "scene.hpp"


MainMenu::MainMenu(Game *game) : Scene(game)
{

}


MainMenu::~MainMenu()
{

}


Vector2 MainMenu::calculate_title_position()
{
    Vector2 title_size {this->get_title_size()};
    Vector2 button_position {this->calculate_button_position()};

    float x {
        (GetScreenWidth() - title_size.x) / 2
    };
    float y {
        (button_position.y - title_size.y) / 2
    };

    return {x, y};
}


Vector2 MainMenu::get_title_size()
{
    return MeasureTextEx(GetFontDefault(), this->title_text, this->title_font_size, this->spacing);
}


bool MainMenu::is_mouse_hover_button()
{
    Vector2 button_position {this->calculate_button_position()};
    Vector2 button_size {this->get_button_size()};

    return  CheckCollisionPointRec(
        GetMousePosition(),
        {button_position.x, button_position.y, button_size.x, button_size.y}
    );
}


Vector2 MainMenu::calculate_button_position()
{
    Vector2 button_size {this->get_button_size()};

    float x {(GetScreenWidth() - button_size.x) / 2};
    float y {(GetScreenHeight() - button_size.y) / 2};

    return {x, y};
}


Vector2 MainMenu::get_button_size()
{
    return MeasureTextEx(GetFontDefault(), this->button_text, this->button_font_size, this->spacing);
}


void MainMenu::check_events()
{
    if (IsMouseButtonReleased(0) && this->is_mouse_hover_button()) {
        this->game->set_scene("level one");
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }
}


void MainMenu::update()
{
    SetMouseCursor(this->is_mouse_hover_button() ? MOUSE_CURSOR_POINTING_HAND : MOUSE_CURSOR_DEFAULT);
}


void MainMenu::draw()
{
    Vector2 title_position {this->calculate_title_position()};
    Vector2 button_position {this->calculate_button_position()};

    ClearBackground(RAYWHITE);
    DrawText(
        this->title_text, title_position.x, title_position.y, this->title_font_size, this->title_color
    );
    DrawText(
        this->button_text, button_position.x, button_position.y, this->button_font_size,
        (this->is_mouse_hover_button() ? this->button_hover_color : this->button_color)
    );
}
