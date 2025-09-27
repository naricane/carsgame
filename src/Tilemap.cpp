#include "Tilemap.hpp"
#include "Texture.hpp"
#include "Tile.hpp"

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

	chunks[key].set_tile(tile_position_in_chunk);
}

void
Tilemap::draw(
	SDL_Renderer* renderer,
	GameTextures& game_textures,
	TileTextures& tile_textures,
	Camera& camera
)
{
	for (auto& chunk : chunks) {
		Vec2i index = {
			int32_t(chunk.first >> 32),
			int32_t(chunk.first),
		};

		chunk.second.draw(renderer, index, game_textures, tile_textures, camera);
	}
}
