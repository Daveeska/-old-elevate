#pragma once

#include "Vec.hpp"

class Rectangle {
public:
	Vec2 pos;
	Vec2 size;
	Vec3 Color;

	virtual void init();
	virtual void update(float dt);
	Rectangle();
};