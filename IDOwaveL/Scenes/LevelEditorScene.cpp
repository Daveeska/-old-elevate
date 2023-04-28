#include "LevelEditorScene.hpp"

#include <iostream>
#include <memory>
#include <SDL.h>

#include "../Window/Window.hpp"

void LevelEditorScene::init() {

	std::cout << "Level Editor Scene has been initialized. \n";
}

void LevelEditorScene::update(float dt, SDL_Event& ev, SDL_Renderer& ren) {
	switch (ev.type) {
	case (SDL_KEYDOWN):
			switch (ev.key.keysym.sym) {
			case SDLK_SPACE:
				
				isSpaceDown = true;

				break;
			}
			break;
	}
	if (isSpaceDown) {
		if (!changingScene) {
			changingScene = true;
		}

		if (changingScene && timeToChangeScene > 0) {
			timeToChangeScene -= dt;
			Window::get()->_r -= dt * 50.0f;
			Window::get()->_g -= dt * 50.0f;
			Window::get()->_b -= dt * 50.0f;
		}
		else if (changingScene && timeToChangeScene < 0) {
			Window::changeScene(LEVEL_SCENE);
		}
	}

	for (std::unique_ptr<Rectangle>& e : Window::get()->recs) {

		SDL_Rect rect;
		rect.x = e->getPos().x;
		rect.y = e->getPos().y;
		rect.w = e->getSize().x;
		rect.h = e->getSize().y;

		SDL_SetRenderDrawColor(&ren, e->getColor().x, e->getColor().y, e->getColor().z, 255);
		SDL_RenderFillRect(&ren, &rect);
	}

}

LevelEditorScene::LevelEditorScene() {
	std::cout << "Level Editor Scene has been loaded. \n";
}