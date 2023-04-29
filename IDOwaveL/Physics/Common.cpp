#include "Common.hpp"

#include <chrono>

long long ifj::get_nanotime() {
    auto now = std::chrono::high_resolution_clock::now();
    auto nanos = std::chrono::time_point_cast<std::chrono::nanoseconds>(now).time_since_epoch().count();
    return nanos;
}


float Time::getTime() {
    return (float)((ifj::get_nanotime() - timeStarted) * 1E-9);
}

bool CollisionDetection::checkAABBCollision(Vec2 e1_pos, Vec2 e1_size, Vec2 e2_pos, Vec2 e2_size)
{
    return e1_pos.x < e2_pos.x + e2_size.x &&
           e1_pos.x + e1_size.x > e2_pos.x &&
           e1_pos.y < e2_pos.y + e2_size.y &&
           e1_pos.y + e1_size.y > e2_pos.y;
}

bool CollisionDetection::checkCollisionPointRec(Vec2 point, Vec2 rect_pos, Vec2 rect_size)
{
    return point.x > rect_pos.x && point.x < rect_pos.x + rect_size.x &&
           point.y > rect_pos.y && point.y < rect_pos.y + rect_size.y;
}

