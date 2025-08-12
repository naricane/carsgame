#include "Tilemap.hpp"
#include "Tile.hpp"

Tilemap::Tilemap(SDL_Renderer* renderer)
	: tile_textures(renderer)
{
}

void
Tilemap::set_tile(Vec2i tile_position)
{
	int chunk_size_bits = log2(CHUNK_SIZE);
	int chunk_size_mask = (1 << chunk_size_bits) - 1;

	Vec2i chunk_index = {
		tile_position.x >> chunk_size_bits,
		tile_position.y >> chunk_size_bits,
	};
	uint64_t key = (uint64_t(std::bit_cast<uint32_t>(chunk_index.x)) << 32)
		| uint64_t(std::bit_cast<uint32_t>(chunk_index.y));

	Vec2i tile_position_in_chunk = {
		tile_position.x & chunk_size_mask,
		tile_position.y & chunk_size_mask,
	};

	if (chunks.contains(key)) {
		chunks.at(key).set_tile(tile_position_in_chunk);
	} else {
		chunks.emplace(key, chunk_index);
		chunks.at(key).set_tile(tile_position_in_chunk);
	}
}

void
Tilemap::draw(SDL_Renderer* renderer, Camera& camera)
{
	for (auto& chunk : chunks) {
		chunk.second.draw(renderer, camera, tile_textures);
	}
}
