#include "Vec.hpp"

Vec2 Vec2::distance(Vec2 anotherVector) {
	return { x - anotherVector.x, y - anotherVector.y };
}

bool Vec2::Equal(Vec2 anotherVector) {
	return x == anotherVector.x && y == anotherVector.y;
}

Vec2::Vec2() {}
Vec2::Vec2(float x, float y) : x{x}, y{y} {}


Vec3 Vec3::distance(Vec3 anotherVector) {
	return { x - anotherVector.x, y - anotherVector.y, z-anotherVector.z };
}

bool Vec3::Equal(Vec3 anotherVector) {
	return x == anotherVector.x && y == anotherVector.y;
}

Vec3::Vec3() {}
Vec3::Vec3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}