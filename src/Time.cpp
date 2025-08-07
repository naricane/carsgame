#include "Time.hpp"
#include <SDL2/SDL_timer.h>

namespace time {
double
real()
{
	return double(SDL_GetPerformanceCounter()) / double(SDL_GetPerformanceFrequency());
}
}
