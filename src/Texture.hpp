#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <string_view>

SDL_Texture*
load_texture(SDL_Renderer* renderer, std::string_view path);
