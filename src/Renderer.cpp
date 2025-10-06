#include "Renderer.hpp"
#include "Texture.hpp"
#include <optional>

Renderer::Renderer(SDL_Renderer* sdl_renderer)
	: sdl_renderer(sdl_renderer)
{
	SDL_SetRenderVSync(sdl_renderer, -1);
}

std::optional<Renderer>
Renderer::make(SDL_Window* window)
{
	SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
	if (!renderer) {
		SDL_Log("SDL_CreateRenderer() Error: %s", SDL_GetError());
		return std::nullopt;
	}

	return Renderer(renderer);
}

TextureHandle
Renderer::load_texture(std::string_view path)
{
	return game_textures.load_texture(sdl_renderer, path);
}

void
Renderer::set_camera(Camera& camera)
{
	this->camera = camera;
}

void
Renderer::clear() const
{
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);
}

void
Renderer::draw(const TextureHandle& texture_handle, const SDL_FRect& rect) const
{
	SDL_FRect draw_rect = camera.to_screen(rect);
	SDL_RenderTexture(sdl_renderer, game_textures.texture(texture_handle), nullptr, &draw_rect);
}

void
Renderer::display() const
{
	SDL_RenderPresent(sdl_renderer);
}
