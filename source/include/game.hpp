# ifndef GAME_HPP
# define GAME_HPP


# include <map>
# include <memory>
# include <string>
# include <vector>
# include <raylib.h>
# include "loading.hpp"
# include "scene.hpp"
# include "scheduled_event.hpp"


class Game
{
private:
    bool running {true};
    bool show_fps_counter {false};
    std::shared_ptr<Scene> scene;
    std::map<std::string, std::shared_ptr<Scene>> scenes {
        {"loading", std::make_shared<Loading> (this)}
    };
    std::vector<std::unique_ptr<ScheduledEvent>> scheduled_events;

    void check_scheduled_events();
    void check_events();
    void update();
    void draw();

public:
    Game();
    ~Game() {};
    void run();
    void quit();
    void set_scene(const char *scene_name);
    void destroy_scene(const char *scene_name);


    template<typename Function, typename ...Args>
    void set_timeout(float seconds, Function function, Args ...args)
    {
        std::unique_ptr<ScheduledEvent> scheduled_event = std::make_unique<ScheduledEvent> (
            false, seconds, function, args...
        );

        this->scheduled_events.push_back(std::move(scheduled_event));
    }


    template<typename Function, typename ...Args>
    void set_interval(float seconds, Function function, Args ...args)
    {
        std::unique_ptr<ScheduledEvent> scheduled_event = std::make_unique<ScheduledEvent> (
            true, seconds, function, args...
        );

        this->scheduled_events.push_back(std::move(scheduled_event));
    }
};


# endif
