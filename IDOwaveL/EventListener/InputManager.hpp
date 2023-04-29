#pragma once

#include <SDL.h>

#include <string>

#include "../Physics/Vec.hpp"

class InputManager {
public:
	enum MOUSE_BUTTONS {
		left = 0,
		right,
		middle,
		back,
		forward
	};

private:
	static InputManager* sInstance;
	
	Uint8* mPrevKeyboardState;
	const Uint8* mKeyboardState;
	int mKeyLength;

	Uint32 mPrevMouseState;
	Uint32 mMouseState;

	int mx = 0;
	int my = 0;

public:
	static InputManager* instance();
	static void Release();

	bool KeyPressed(SDL_Scancode scancode);
	bool KeyDown(SDL_Scancode scanCode);
	bool KeyReleased(SDL_Scancode scancode);

	bool MouseDown(int button);
	bool MousePressed(MOUSE_BUTTONS button);
	bool MouseReleased(MOUSE_BUTTONS button);

	Vec2 GetMousePos();
	
	void Update();
	void UpdatePrevInput();

private:
	InputManager();
	~InputManager();
};