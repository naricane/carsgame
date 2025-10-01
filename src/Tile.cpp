#include "Tile.hpp"
#include <SDL3_image/SDL_image.h>
#include <cstdio>

TileTextures::TileTextures(Renderer& renderer)
{
	texture_ids[std::size_t(TileType::None)] = renderer.load_texture("assets/tiles/none.png");
	texture_ids[std::size_t(TileType::Asphalt)] = renderer.load_texture("assets/tiles/asphalt.png");
}
