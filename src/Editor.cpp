#include "Editor.hpp"
#include <SDL3_image/SDL_image.h>
#include <cstdio>

Editor::Editor(SDL_Renderer* renderer)
{
	texture = IMG_LoadTexture(renderer, "assets/tiles/asphalt.png");
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
}

void
Editor::draw(SDL_Renderer* renderer, double alpha)
{
	for (size_t y = 0; y < 64; y++) {
		for (size_t x = 0; x < 64; x++) {
			SDL_FRect draw_rect = camera.to_screen({ x * 16.f, y * 16.f, 16.f, 16.f });

			SDL_RenderTexture(renderer, texture, nullptr, &draw_rect);
		}
	}
}
