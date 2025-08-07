#pragma once

#include "Math.hpp"
#include <SDL3/SDL.h>

class Car
{
private:
	SDL_Texture* texture;
	SDL_FRect rect;
	SDL_FRect previous_rect;
	float heading = 0.0;
	float speed = 0.0;
	Vec2 direction = { 0, 0 };

public:
	Car(SDL_Renderer* renderer);

	void update();
	void draw(SDL_Renderer* renderer, double alpha);
};
