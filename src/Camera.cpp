#include "Camera.hpp"

void
Camera::zoom_in(int delta)
{
	zoom_level += delta;
	zoom_level = math::clamp(zoom_level, -8.f, 24.f);
	zoom_value = powf(2.f, zoom_level * 0.25f);
}

void
Camera::pan_around(Vec2 offset)
{
	this->offset += offset / zoom_value;
}

Vec2
Camera::to_screen(Vec2 world)
{
	return {
		(world.x - offset.x) * zoom_value,
		(world.y - offset.y) * zoom_value,
	};
}

SDL_FRect
Camera::to_screen(SDL_FRect world)
{
	return { (world.x - offset.x) * zoom_value,
			 (world.y - offset.y) * zoom_value,
			 world.w * zoom_value,
			 world.h * zoom_value };
}

Vec2
Camera::to_world(Vec2 screen)
{
	return { screen.x / zoom_value + offset.x, screen.y / zoom_value + offset.y };
}

float
Camera::zoom()
{
	return zoom_value;
}
