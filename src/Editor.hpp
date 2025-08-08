#pragma once
#include "Camera.hpp"
#include "Constants.hpp"
#include <SDL3/SDL.h>
#include <array>

enum class TileType
{
	None,
	Asphalt
};

class Editor
{
private:
	std::array<TileType, 64 * 64> tiles;
	SDL_Texture* texture;
	Camera camera;

	Vec2 last_mouse_position;
	bool dragging = false;
	uint32_t window_width = DEFAULT_WINDOW_WIDTH, window_height = DEFAULT_WINDOW_HEIGHT;

public:
	Editor(SDL_Renderer* renderer);
	void handle_events(SDL_Event& event);
	void update();
	void draw(SDL_Renderer* renderer, double alpha);
};
