#include "LevelEditorScene.hpp"

#include <iostream>
#include <memory>
#include <SDL.h>

#include "../Window/Window.hpp"

void LevelEditorScene::init() {

	for (std::unique_ptr<Rectangle>& e : Window::get()->recs) {
		e->init();
	}

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
		rect.x = e->pos.x;
		rect.y = e->pos.y;
		rect.w = e->size.x;
		rect.h = e->size.y;

		SDL_SetRenderDrawColor(&ren, e->Color.x, e->Color.y, e->Color.z, 255);
		SDL_RenderFillRect(&ren, &rect);
	}

}

LevelEditorScene::LevelEditorScene() {
	std::cout << "Level Editor Scene has been loaded. \n";
}