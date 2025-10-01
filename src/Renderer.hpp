#pragma once

#include "Camera.hpp"
#include "Texture.hpp"
#include <SDL3/SDL.h>
#include <optional>

class Renderer
{
private:
	SDL_Renderer* sdl_renderer;
	GameTextures game_textures;
	Camera camera;

	Renderer(SDL_Renderer* renderer);

public:
	static std::optional<Renderer> make(SDL_Window* window);

	uint32_t load_texture(std::string_view path);

	void set_camera(Camera& camera);
	void clear();
	void draw(uint32_t texture_id, SDL_FRect& rect);
	void display();
};
