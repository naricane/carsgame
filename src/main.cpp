#include "Constants.hpp"
#include "Editor.hpp"
#include "Game.hpp"
#include "Time.hpp"

int
main(int argc, char** args)
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("SDL_Init() Error: %s", SDL_GetError());
		return -1;
	}

	window = SDL_CreateWindow(
		"carsgame", DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE
	);
	if (!window) {
		SDL_Log("SDL_CreateWindow() Error: %s", SDL_GetError());
		return -1;
	}

	renderer = SDL_CreateRenderer(window, nullptr);
	if (!window) {
		SDL_Log("SDL_CreateRenderer() Error: %s", SDL_GetError());
		return -1;
	}

	SDL_SetRenderVSync(renderer, -1);

	SDL_Event event;
	bool running = true;

	// Game game(renderer);
	Editor editor(renderer);

	double t = 0.0;
	const double dt = 0.01;

	double current_time = time::real();
	double accumulator = 0.0;

	int ticks = 0;

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					running = false;
					break;
				default:
					break;
			}
			editor.handle_events(event);
		}
		double new_time = time::real();
		double frame_time = new_time - current_time;
		current_time = new_time;

		accumulator += frame_time;

		while (accumulator >= dt) {
			ticks++;
			// game.update();
			editor.update();
			accumulator -= dt;
			t += dt;
		}

		SDL_RenderClear(renderer);
		const double alpha = accumulator / dt;
		// game.draw(renderer, alpha);
		editor.draw(renderer, alpha);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
