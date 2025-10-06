#pragma once
#include "Renderer.hpp"
#include <SDL3/SDL_render.h>
#include <array>

constexpr int TILE_SIZE = 16;

enum class TileType
{
	None,
	Asphalt,

	Max
};

class TileTextures
{
private:
	std::array<TextureHandle, std::size_t(TileType::Max)> texture_handles;

public:
	TileTextures(Renderer& renderer);

	TextureHandle operator[](TileType tile_type) { return texture_handles[std::size_t(tile_type)]; }
};
