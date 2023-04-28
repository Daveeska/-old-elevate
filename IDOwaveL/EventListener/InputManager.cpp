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
	mKeyboardState = SDL_GetKeyboardState(&mKeyLength);
	mPrevKeyboardState = new Uint8[mKeyLength];
	memcpy(mPrevKeyboardState, mKeyboardState, mKeyLength);
}

InputManager::~InputManager() {
	delete[] mPrevKeyboardState;
	mPrevKeyboardState = NULL;
}

bool InputManager::KeyDown(SDL_Scancode scanCode) {
	return mKeyboardState[scanCode];
}

bool InputManager::KeyPressed(SDL_Scancode scanCode) {
	return !mPrevKeyboardState[scanCode] && mKeyboardState[scanCode];
}

bool InputManager::KeyReleased(SDL_Scancode scanCode) {
	return mPrevKeyboardState[scanCode] && !mKeyboardState[scanCode];
}

Vec2 InputManager::GetMousePos() {
	return Vec2((float)mx, (float)my);
}

bool InputManager::MouseDown(MOUSE_BUTTONS button) {
	Uint32 mask = 0;
	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;
	case right:
		mask = SDL_BUTTON_RMASK;
		break;
	case middle:
		mask = SDL_BUTTON_MMASK;
		break;
	case back:
		mask = SDL_BUTTON_X1MASK;
		break;
	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return (mMouseState & mask);
}

bool InputManager::MousePressed(MOUSE_BUTTONS button) {
	Uint32 mask = 0;
	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;
	case right:
		mask = SDL_BUTTON_RMASK;
		break;
	case middle:
		mask = SDL_BUTTON_MMASK;
		break;
	case back:
		mask = SDL_BUTTON_X1MASK;
		break;
	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return !(mPrevMouseState & mask) && (mMouseState & mask);
}

bool InputManager::MouseReleased(MOUSE_BUTTONS button) {
	Uint32 mask = 0;
	switch (button) {
	case left:
		mask = SDL_BUTTON_LMASK;
		break;
	case right:
		mask = SDL_BUTTON_RMASK;
		break;
	case middle:
		mask = SDL_BUTTON_MMASK;
		break;
	case back:
		mask = SDL_BUTTON_X1MASK;
		break;
	case forward:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return (mPrevMouseState & mask) && !(mMouseState & mask);
}

void InputManager::Update() {
	SDL_GetMouseState(&mx, &my);
}
void InputManager::UpdatePrevInput() {
	memcpy(mPrevKeyboardState, mKeyboardState, mKeyLength);
	mPrevMouseState = mMouseState;
}