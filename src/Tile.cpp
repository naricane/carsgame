#include "Tile.hpp"
#include "Texture.hpp"
#include <SDL3_image/SDL_image.h>
#include <cstdio>

TileTextures::TileTextures(SDL_Renderer* renderer, GameTextures& game_textures)
{
	texture_ids[std::size_t(TileType::None)]
		= game_textures.load_texture(renderer, "assets/tiles/none.png");
	texture_ids[std::size_t(TileType::Asphalt)]
		= game_textures.load_texture(renderer, "assets/tiles/asphalt.png");
}
