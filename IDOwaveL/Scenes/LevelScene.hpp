#pragma once

#include "Scene.hpp"

#include <SDL.h>

class LevelScene : public Scene {
public:
	void init();
	void update(float dt, SDL_Event &ev, SDL_Renderer& ren);
	LevelScene();
};