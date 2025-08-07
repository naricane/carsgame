#include "Car.hpp"
#include <SDL3_image/SDL_image.h>

Car::Car(SDL_Renderer* renderer)
{
	texture = IMG_LoadTexture(renderer, "assets/cars/orange.png");
	SDL_GetTextureSize(texture, &rect.w, &rect.h);
	rect.x = 0;
	rect.y = 0;
}

void
Car::update()
{
	const bool* keys = SDL_GetKeyboardState(nullptr);
	speed = 0.0;
	if (keys[SDL_SCANCODE_UP]) {
		speed = 4.0;
	}
	if (keys[SDL_SCANCODE_LEFT]) {
		heading -= 2.0;
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		heading += 2.0;
	}
	direction = { (float)cos(math::deg_to_rad(heading)), (float)sin(math::deg_to_rad(heading)) };

	previous_rect = rect;
	rect.x += direction.x * speed;
	rect.y += direction.y * speed;
}

void
Car::draw(SDL_Renderer* renderer, double alpha)
{
	SDL_FRect draw_rect = rect;
	draw_rect.x = rect.x * alpha + previous_rect.x * (1.0 - alpha);
	draw_rect.y = rect.y * alpha + previous_rect.y * (1.0 - alpha);

	SDL_RenderTextureRotated(
		renderer, texture, nullptr, &draw_rect, heading, nullptr, SDL_FLIP_NONE
	);
}
