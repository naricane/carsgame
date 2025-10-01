#include "Editor.hpp"
#include "Texture.hpp"
#include "Tile.hpp"

Editor::Editor(Renderer& renderer)
	: tile_textures(renderer)
{
	cursor = renderer.load_texture("assets/editor/cursor.png");
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
			camera.pan_around(Vec2{ event.wheel.mouse_x, event.wheel.mouse_y });
			camera.zoom_in(event.wheel.integer_y);
			camera.pan_around(-Vec2{ event.wheel.mouse_x, event.wheel.mouse_y });
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
	Vec2 mouse_position;
	SDL_GetMouseState(&mouse_position.x, &mouse_position.y);

	Vec2 mouse_world = camera.to_world({ mouse_position.x, mouse_position.y });
	int tile_size_bits = log2(TILE_SIZE);
	Vec2i tile_position{
		int(mouse_world.x) >> tile_size_bits,
		int(mouse_world.y) >> tile_size_bits,
	};

	if (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON_LEFT) {
		tilemap.set_tile(tile_position);
	}

	cursor_rect = {
		float(tile_position.x * TILE_SIZE),
		float(tile_position.y * TILE_SIZE),
		TILE_SIZE,
		TILE_SIZE,
	};
}

void
Editor::draw(Renderer& renderer, double alpha)
{
	renderer.set_camera(camera);
	tilemap.draw(renderer, tile_textures);
	renderer.draw(cursor, cursor_rect);
}
