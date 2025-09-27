#pragma once
#include "Camera.hpp"
#include "Constants.hpp"
#include "Texture.hpp"
#include "Tilemap.hpp"
#include <SDL3/SDL.h>
#include <Tile.hpp>

class Editor
{
private:
	GameTextures game_textures;
	Tilemap tilemap;
	TileTextures tile_textures;
	Camera camera;

	Vec2 last_mouse_position;
	bool dragging = false;
	uint32_t window_width = DEFAULT_WINDOW_WIDTH;
	uint32_t window_height = DEFAULT_WINDOW_HEIGHT;

	uint32_t cursor;
	SDL_FRect cursor_rect;

public:
	Editor(SDL_Renderer* renderer);
	void handle_events(SDL_Event& event);
	void update();
	void draw(SDL_Renderer* renderer, double alpha);
};
