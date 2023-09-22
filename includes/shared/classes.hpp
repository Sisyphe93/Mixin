#ifndef CLASSESS_HPP
#define CLASSESS_HPP

#include <SDL2/SDL.h>
#include "iostream"
using namespace std;

class Window
{
public:
	SDL_Renderer *renderer;
	SDL_Window *window;
};

#endif