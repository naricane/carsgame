#pragma once
#include "Car.hpp"
#include <SDL3/SDL.h>

class Game
{
private:
	Car car;

public:
	Game(SDL_Renderer* renderer);
	void update();
	void draw(SDL_Renderer* renderer);
};
