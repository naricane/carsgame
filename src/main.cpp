#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <cmath>

struct Vec2
{
	float x, y;
};

class Car
{
private:
	SDL_Texture* texture;
	SDL_FRect rect;
	float heading = 0;
	float speed = 0.0;
	Vec2 direction = { 0, 0 };

public:
	Car(SDL_Renderer* renderer)
	{
		texture = IMG_LoadTexture(renderer, "assets/cars/orange.png");
		SDL_GetTextureSize(texture, &rect.w, &rect.h);
		rect.x = 0;
		rect.y = 0;
	}

	void update()
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
		direction = { (float)cos(heading * 3.14 / 180.0), (float)sin(heading * 3.14 / 180.0) };

		rect.x += direction.x * speed;
		rect.y += direction.y * speed;
	}
	void draw(SDL_Renderer* renderer)
	{
		SDL_RenderTextureRotated(
			renderer, texture, nullptr, &rect, heading, nullptr, SDL_FLIP_NONE
		);
	}
};

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

	Car car(renderer);

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

		car.update();

		SDL_RenderClear(renderer);
		car.draw(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
