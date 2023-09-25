#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "defs.hpp"
#include "../shared/classes.hpp"
#include "../inputs_system/inputs.hpp"

SDL_Texture *loadTexture(const char *filename, Window *app);
void blit(Window *app, SDL_Texture *texture, Entity player);

#endif