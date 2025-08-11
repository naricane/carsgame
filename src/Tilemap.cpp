#include "Tilemap.hpp"
#include "Tile.hpp"

Tilemap::Tilemap(SDL_Renderer* renderer)
	: tile_textures(renderer)
{
}

void
Tilemap::set_tile(int x, int y)
{
	int chunk_size_bits = 6;
	int chunk_size_mask = (1 << chunk_size_bits) - 1;

	int32_t chunk_x = x >> chunk_size_bits, chunk_y = y >> chunk_size_bits;
	uint64_t key = (uint64_t(std::bit_cast<uint32_t>(chunk_x)) << 32)
		| uint64_t(std::bit_cast<uint32_t>(chunk_y));

	chunks[key].set_tile(x & chunk_size_mask, y & chunk_size_mask);
	chunks[key].set_index(chunk_x, chunk_y);
}

void
Tilemap::draw(SDL_Renderer* renderer, Camera& camera)
{
	for (auto& chunk : chunks) {
		chunk.second.draw(renderer, camera, tile_textures);
	}
}
