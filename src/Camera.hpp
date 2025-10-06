#pragma once
#include "Math.hpp"
#include <SDL3/SDL_rect.h>

class Camera
{
private:
	Vec2 offset = { 0.f, 0.f };
	float zoom_value = 1.f;
	int zoom_level = 0;

public:
	void zoom_in(int delta);
	void pan_around(Vec2 offset);

	Vec2 to_screen(Vec2 world) const;
	SDL_FRect to_screen(SDL_FRect world) const;
	Vec2 to_world(Vec2 screen) const;
};
