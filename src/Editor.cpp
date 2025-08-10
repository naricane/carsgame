#include "Editor.hpp"
#include "Texture.hpp"
#include "Tile.hpp"
#include <cstdio>

Editor::Editor(SDL_Renderer* renderer)
	: tile_textures(renderer)
{
	cursor = load_texture(renderer, "assets/editor/cursor.png");
}

void
Editor::handle_events(SDL_Event& event)
{
	switch (event.type) {
		case SDL_EVENT_MOUSE_MOTION: {
			Vec2 current_mouse_position = { event.motion.x, event.motion.y };
			if (dragging) {
				camera.pan_around(last_mouse_position - current_mouse_position);
			}
			last_mouse_position = current_mouse_position;
		} break;
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				dragging = true;
			}
			break;
		case SDL_EVENT_MOUSE_BUTTON_UP:
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				dragging = false;
			}
			break;
		case SDL_EVENT_MOUSE_WHEEL:
			camera.pan_around(Vec2{ window_width / 2.f, window_height / 2.f });
			camera.zoom_in(event.wheel.integer_y);
			camera.pan_around(-Vec2{ window_width / 2.f, window_height / 2.f });
			break;
		case SDL_EVENT_WINDOW_RESIZED:
			window_width = event.window.data1;
			window_height = event.window.data2;
		default:
			break;
	}
}

void
Editor::update()
{
	float mouse_x, mouse_y;
	SDL_GetMouseState(&mouse_x, &mouse_y);

	Vec2 mouse_world = camera.to_world({ mouse_x, mouse_y });
	Vec2 mouse_tile = { std::floor(mouse_world.x / 16.f), std::floor(mouse_world.y / 16.f) };

	cursor_rect = { mouse_tile.x * 16.f, mouse_tile.y * 16.f, 16.f, 16.f };

	if (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_LEFT) {
		tiles[mouse_tile.x + mouse_tile.y * 64] = TileType::Asphalt;
	}
}

void
Editor::draw(SDL_Renderer* renderer, double alpha)
{
	for (size_t y = 0; y < 64; y++) {
		for (size_t x = 0; x < 64; x++) {
			SDL_FRect draw_rect = camera.to_screen(
				{ float(x * TILE_SIZE), float(y * TILE_SIZE), TILE_SIZE, TILE_SIZE }
			);

			SDL_RenderTexture(renderer, tile_textures[tiles[x + y * 64]], nullptr, &draw_rect);
		}
	}

	SDL_FRect draw_rect = camera.to_screen(cursor_rect);
	SDL_RenderTexture(renderer, cursor, nullptr, &draw_rect);
}
