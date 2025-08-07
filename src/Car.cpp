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
		speed = 2.0;
	}
	if (keys[SDL_SCANCODE_LEFT]) {
		heading -= 1.0;
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		heading += 1.0;
	}
	direction = { (float)cos(math::deg_to_rad(heading)), (float)sin(math::deg_to_rad(heading)) };

	rect.x += direction.x * speed;
	rect.y += direction.y * speed;
}
void
Car::draw(SDL_Renderer* renderer)
{
	SDL_RenderTextureRotated(renderer, texture, nullptr, &rect, heading, nullptr, SDL_FLIP_NONE);
}
