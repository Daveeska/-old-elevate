#pragma once

#include <string>
#include <vector>
#include <memory>
#include <SDL.h>

#include "../Scenes/Scene.hpp"
#include "../Physics/Rectangle.hpp"
#include "../EventListener/InputManager.hpp"

class Window {
//Variables
private:
    //The actual window properties
    std::string title;
    int width, height;
    bool is_closed = false;

    //Other stuff
    SDL_Renderer* renderer = nullptr;
    SDL_Window* sdl_window = nullptr;
    SDL_Event w_event;

    //Singleton stuff
    static inline Window* window = NULL;
    Scene* current_scene;

//Functions
private:
    void clear() const;
    void init();
    void loop();
    Window();

public:
    //Public variables
    InputManager* mInputManager;
    std::vector<std::unique_ptr<Rectangle>> recs;
    Uint8 _r, _g, _b;

    //public functions;
    static void changeScene(Scenes newScene);
    static Window* get();
    void addEntity(std::unique_ptr<Rectangle> rec);
    void run();
    void pollEvents();
};

