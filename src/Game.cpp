#include "Game.hpp"

Game::Game(SDL_Renderer* renderer)
	: car(renderer)
{
}

void
Game::update()
{
	car.update();
}

void
Game::draw(SDL_Renderer* renderer)
{
	car.draw(renderer);
}
