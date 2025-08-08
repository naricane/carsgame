#include "Math.hpp"

namespace vector {

float
length(Vec2 v)
{
	return std::sqrt(v.x * v.x + v.y * v.y);
}

float
dot(Vec2 a, Vec2 b)
{
	return a.x * b.x + a.y * b.y;
}

float
cross(Vec2 a, Vec2 b)
{
	return a.x * b.y - a.y * b.x;
}

Vec2
normalize(Vec2 v)
{
	return { .x = v.x / length(v), .y = v.y / length(v) };
}

float
angle(Vec2 a, Vec2 b)
{
	return std::atan2(cross(a, b), dot(a, b));
}

}

namespace math {

float
clamp(float value, float min, float max)
{
	if (value > max) {
		return max;
	} else if (value < min) {
		return min;
	} else {
		return value;
	}
}

float
deg_to_rad(float deg)
{
	return deg * M_PI / 180.f;
}

float
rad_to_deg(float rad)
{
	return rad * 180.f / M_PI;
}

}
