#pragma once

#include "Vec.hpp"

class ifj {
public:
	static long long get_nanotime();
};

static long long timeStarted = ifj::get_nanotime();

class Time
{
public:
	static float getTime();
};

namespace CollisionDetection {
	bool checkAABBCollision(Vec2 e1_pos, Vec2 e1_size, Vec2 e2_pos, Vec2 e2_size);
	bool checkCollisionPointRec(Vec2 point, Vec2 rect_pos, Vec2 rect_size);
}