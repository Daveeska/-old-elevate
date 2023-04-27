#pragma once

struct Vec2 {
	float x, y;
	Vec2 distance(Vec2 anotherVector);
	bool Equal(Vec2 anotherVector);
	Vec2(float x, float y);
};

struct Vec3 {
	float x, y, z;
	Vec3 distance(Vec3 anotherVector);
	bool Equal(Vec3 anotherVector);
	Vec3(float x, float y, float z);
};