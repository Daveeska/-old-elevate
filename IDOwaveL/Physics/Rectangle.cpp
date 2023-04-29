#include "Rectangle.hpp"

void Rectangle::Move(Vec2 vc2Target){
	pos.x += vc2Target.x;
	pos.y += vc2Target.y;
}

Vec2 Rectangle::getPos() {
	return pos;
}

Vec2 Rectangle::getSize() {
	return size;
}

Vec3 Rectangle::getColor() {
	return Color;
}

void Rectangle::reSize(Vec2 New_size) {
	this->size = New_size;
}

void Rectangle::rePos(Vec2 New_Position) {
	this->pos = New_Position;
}

void Rectangle::reColor(Vec3 New_Color) {
	this->Color = New_Color;
}

void Rectangle::init() {

}

void Rectangle::update(float dt) {

}

Rectangle::Rectangle() {

}