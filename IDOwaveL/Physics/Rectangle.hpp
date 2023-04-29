#pragma once

#include "Vec.hpp"

class Rectangle {
protected:
	Vec2 pos;
	Vec2 size;
	Vec3 Color;

	void Move(Vec2 vc2Target);

public:
	Vec2 getPos();
	Vec2 getSize();
	Vec3 getColor();

	void reSize(Vec2 New_size);
	void reColor(Vec3 New_Color);
	void rePos(Vec2 New_Position);

	virtual void init();
	virtual void update(float dt);
	Rectangle();
};