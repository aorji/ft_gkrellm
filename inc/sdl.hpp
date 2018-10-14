#ifndef SDL_HPP
# define SDL_HPP

#include "CPU.hpp"
# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>
# include <iostream>

class Sdl
{
public:
	Sdl();
	~Sdl();

	void			init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void			handleEvents();
	void			update();
	void			render();
	void			clean();

	bool			running() {return isRunning;}

private:
	bool			isRunning;
	SDL_Window 		*window;
	TTF_Font 		*font;

	SDL_Surface * s;
	SDL_Color color;
	
};

#endif