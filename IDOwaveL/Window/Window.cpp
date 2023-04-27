#include "Window.hpp"

#include <iostream>
#include <memory>

#include "../Scenes/LevelEditorScene.hpp"
#include "../Scenes/LevelScene.hpp"
#include "../Physics/Common.hpp"

Window::Window() {
    this->title = "Game Window";
    this->width = 1280;
    this->height = 720;

    this->_r = 255;
    this->_g = 255;
    this->_b = 255;

}

Window* Window::get(){
    if(window==NULL){
        window = new Window();
    }

    return window;
}

void Window::addEntity(std::unique_ptr<Rectangle> rec)
{
    recs.push_back(rec);
}

void Window::changeScene(Scenes newScene) {
    switch (newScene) {
    case 0:
        get()->current_scene = new LevelEditorScene();
        get()->current_scene->init();
        break;
    case 1:
        get()->current_scene = new LevelScene();
        get()->current_scene->init();
        break;
    default:
        break;
    }
}

void Window::clear() const {

    SDL_Rect rect;
    rect.w = 120;
    rect.h = 120;
    rect.x = width / 2;
    rect.y = height / 2;

    SDL_SetRenderDrawColor(renderer, 10, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void Window::init(){
    if (SDL_Init(SDL_INIT_VIDEO)!=0) {
        std::cerr << "Failed to initialize SDL(video). \n";
        return;
    }
    else {
        std::cout << "SDL has been initialize. \n";
    }

    sdl_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (sdl_window == nullptr) {
        std::cerr << "Failed to create window. \n";
        return;
    }
    else {
        std::cout << "(SDL) Window has been created. \n";
    }

    renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Failed to create renderer. \n";
        return;
    }
    else {
        std::cout << "(SDL) Renderer has been created. \n";
    }


    changeScene(LEVEL_EDITOR_SCENE);
}

void Window::loop(){

    float beginTime = Time::getTime();
    float endTime = Time::getTime();
    float dt = -1;

    while (!is_closed) {
        pollEvents();

        SDL_SetRenderDrawColor(renderer, _r, _g, _b, 255);
        SDL_RenderClear(renderer);
        
        if (dt >= 0)
            current_scene->update(dt, w_event, *renderer);

        SDL_RenderPresent(renderer);

        endTime = Time::getTime();
        dt = endTime - beginTime;
        beginTime = endTime;
    }
}

void Window::run(){
    init();
    loop();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(sdl_window);

    delete window;

    SDL_Quit();
}


void Window::pollEvents()
{
    if (SDL_PollEvent(&w_event)) {
        switch (w_event.type){
        case SDL_QUIT:
            is_closed = true;
            break;
        default:
            break;
        }
    }
}
