#pragma once

#include <SDL.h>

typedef enum {
	LEVEL_EDITOR_SCENE,
	LEVEL_SCENE
}Scenes;

class Scene {
public:
	virtual void init() = 0;
	virtual void update(float dt, SDL_Event &ev, SDL_Renderer& ren) = 0;
	Scene();
};