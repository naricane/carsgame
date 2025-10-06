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

	TextureHandle load_texture(std::string_view path);

	void set_camera(Camera& camera);
	void clear() const;
	void draw(const TextureHandle& texture_id, const SDL_FRect& rect) const;
	void display() const;
};
