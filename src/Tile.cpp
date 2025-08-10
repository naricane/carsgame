#include "Tile.hpp"
#include "Texture.hpp"
#include <SDL3_image/SDL_image.h>

TileTextures::TileTextures(SDL_Renderer* renderer)
{
	textures[std::size_t(TileType::None)] = load_texture(renderer, "assets/tiles/none.png");
	textures[std::size_t(TileType::Asphalt)] = load_texture(renderer, "assets/tiles/asphalt.png");
}
