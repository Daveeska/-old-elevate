#include "LevelScene.hpp"

#include <iostream>
#include <SDL.h>

#include "../Window/Window.hpp"

void LevelScene::init() {
	
	Window::get()->_r = 255;
	Window::get()->_g = 255;
	Window::get()->_b = 255;

	std::cout << "Level Scene has been initialize. \n";
}

void LevelScene::update(float dt, SDL_Event& ev, SDL_Renderer& ren)
{
}



LevelScene::LevelScene() {
	std::cout << "Level Scene has been loaded. \n";
}