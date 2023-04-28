#include <memory>

#include "Window/Window.hpp"
#include "Physics/Rectangle.hpp"
#include "Physics/Vec.hpp"

class Player : public Rectangle {
public:
	
	void init() override {
		this->Color = { 255,130,240 };
		this->pos = { 500, 550 };
		this->size = { 50,50 };
	}

	void update(float dt) override {
		if (Window::get()->mInputManager->KeyDown(SDL_SCANCODE_W)) this->Move({ 0, -200*dt });
		if (Window::get()->mInputManager->KeyDown(SDL_SCANCODE_A)) this->Move({ -200*dt, 0 });
		if (Window::get()->mInputManager->KeyDown(SDL_SCANCODE_S)) this->Move({ 0, 200*dt });
		if (Window::get()->mInputManager->KeyDown(SDL_SCANCODE_D)) this->Move({ 200*dt, 0 });

	}

	Player() {
		
	}

	~Player()
	{
		delete &Color;
		delete &pos;
		delete &size;
	}

};

int main(int argc, char **argv) {

	Window* window = Window::get();
	window->addEntity(std::make_unique<Player>());
	window->run();

	return 0;
}