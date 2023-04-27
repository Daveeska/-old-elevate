#pragma once

#include <string>
#include <vector>
#include <memory>
#include <SDL.h>

#include "../Scenes/Scene.hpp"
#include "../Physics/Rectangle.hpp"


class Window {
//Variables
private:
    std::string title;
    int width, height;
    bool is_closed = false;
    SDL_Renderer* renderer = nullptr;
    SDL_Window* sdl_window = nullptr;
    static inline Window* window = NULL;
    Scene* current_scene;
    SDL_Event w_event;

//Functions
private:
    void clear() const;
    void init();
    void loop();
    Window();
public:
    std::vector<std::unique_ptr<Rectangle>> recs;
    Uint8 _r, _g, _b;
    static void changeScene(Scenes newScene);
    static Window* get();
    void addEntity(std::unique_ptr<Rectangle> rec);
    void run();
    void pollEvents();
};

