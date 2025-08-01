#include <SDL3/SDL.h>

int
main(int argc, char** args)
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("SDL_Init() Error: %s", SDL_GetError());
		return -1;
	}

	window = SDL_CreateWindow("carsgame", 800, 600, SDL_WINDOW_RESIZABLE);
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

	while (running) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_EVENT_QUIT:
					running = false;
					break;
				default:
					break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
