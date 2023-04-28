#include "LevelScene.hpp"

#include <iostream>
#include <SDL.h>

#include "../Window/Window.hpp"

void LevelScene::init() {
	
	Window::get()->_r = 255;
	Window::get()->_g = 255;
	Window::get()->_b = 255;

	for (std::unique_ptr<Rectangle>& e : Window::get()->recs) {
		e->init();
	}

	std::cout << "Level Scene has been initialize. \n";
}

void LevelScene::update(float dt, SDL_Event& ev, SDL_Renderer& ren)
{
	for (std::unique_ptr<Rectangle>& e : Window::get()->recs) {
		e->update(dt);

		SDL_Rect rect;
		rect.x = e->getPos().x;
		rect.y = e->getPos().y;
		rect.w = e->getSize().x;
		rect.h = e->getSize().y;

		SDL_SetRenderDrawColor(&ren, e->getColor().x, e->getColor().y, e->getColor().z, 255);
		SDL_RenderFillRect(&ren, &rect);
	}
}



LevelScene::LevelScene() {
	std::cout << "Level Scene has been loaded. \n";
}