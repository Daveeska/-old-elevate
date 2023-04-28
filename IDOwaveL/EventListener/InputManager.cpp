#include "InputManager.hpp"

InputManager* InputManager::sInstance = NULL;

InputManager* InputManager::instance() {
	if (sInstance == NULL) {
		sInstance = new InputManager();
	}

	return sInstance;
}

void InputManager::Release() {
	delete sInstance;
	sInstance = NULL;
}

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return mKeyboardState[scanCode];
}

void InputManager::Update() {
	mKeyboardState = SDL_GetKeyboardState(NULL);
}