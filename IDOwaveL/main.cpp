#include <memory>

#include "Window/Window.hpp"
#include "Physics/Rectangle.cpp"
#include "Physics/Vec.hpp"

class Player : public Rectangle {
public:
	void init() override {
		this->Color = { 255,130,240 };
		this->pos = { 500, 550 };
		this->size = { 50,50 };
	}

	void update(float dt) override {
		
	}

	//Boring shit
	Player() {

	}

	~Player()
	{
		
	}

};

int main(int argc, char **argv) {

	std::unique_ptr<Player> plr;

	Window* window = Window::get();
	window->recs.push_back(std::move(plr));
	window->run();

	return 0;
}