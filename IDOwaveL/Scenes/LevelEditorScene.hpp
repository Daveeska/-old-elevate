#pragma once

#include "Scene.hpp"

#include <SDL.h>

#include "../Physics/Vec.hpp"

class LevelEditorScene : public Scene {
private:
	bool changingScene = false;
	bool isSpaceDown = false;
	float timeToChangeScene = 2.0f;

public:
	void init();
	void update(float dt, SDL_Event& ev, SDL_Renderer& ren);
	LevelEditorScene();
};