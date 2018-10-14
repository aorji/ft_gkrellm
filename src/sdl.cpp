#include "../inc/sdl.hpp"
#include "../inc/CPU.hpp"
#include "../inc/OS.hpp"
#include "../inc/Disk.hpp"
#include "../inc/Host.hpp"
#include "../inc/Network.hpp"
#include "../inc/Time.hpp"
#include "../inc/Processes.hpp"
#include "../inc/RAM.hpp"


int texW = 350;
int texH = 100;


SDL_Rect dstrect = { 0, 0, texW, texH };

SDL_Rect dstrectNW = { 50, 70, texW, texH };

SDL_Rect dstrectProc = { 50, 100, texW, texH };

SDL_Rect dstrectRam = { 50, 130, texW, texH };
SDL_Rect dstrectCPU = { 50, 160, texW, texH };
SDL_Rect dstrectDisk = { 50, 190, texW, texH };


SDL_Rect dstrectOS3 = { 50, 280, texW, texH };
SDL_Rect dstrectTime = { 50, 310, texW, texH };


SDL_Rect dstrectTime2 = { 50, 340, texW, texH };

SDL_Rect dstrectHost = { 50, 370, texW, texH };



SDL_Rect dstrectHost2 = { 50, 400, texW, texH };
SDL_Rect dstrectOS = { 50, 220, texW, texH };
SDL_Rect dstrectOS2 = { 50, 250, texW, texH };

CPU 	cpu;
OS 		os;
Host 	host;
Disk 	disk;
Network nw;
Time timeDate;
Processes pr;
RAM ram;

Sdl::Sdl()
{}
Sdl::~Sdl()
{}

void	Sdl::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	TTF_Init();
	font = TTF_OpenFont("arial.ttf", 20);
	SDL_Color tmpColor = { 34, 139, 34, 255 };

	color = tmpColor;

	if (!font)
		std::cout << "Error!" << std::endl;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (!window) {
			std::cout << "Window  didn't created!" << std::endl;
		}
		s = SDL_GetWindowSurface(window);
		SDL_memset(s->pixels, 54, s->h * s->pitch);
		isRunning = true;
	}
	else {
		isRunning = false;
	}

}

void	Sdl::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

			default:
				break;
	}
}

void	Sdl::update()
{

	std::string str = "Date: ";
	std::string tmp;
	std::string tmp2;

	SDL_Surface* tmpSurface = IMG_Load("print.bmp");

	SDL_BlitSurface(tmpSurface, NULL, s, &dstrect);
	SDL_FreeSurface(tmpSurface);

	tmp = cpu.getCPU();
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface, NULL, s, &dstrectCPU);
	SDL_FreeSurface(surface);

	str = str + timeDate.getDate();
	SDL_Surface * surface2 = TTF_RenderText_Solid(font, str.c_str(), color);
	SDL_BlitSurface(surface2, NULL, s, &dstrectTime);
	SDL_FreeSurface(surface2);

	str = "Time: " + timeDate.getTime();
	SDL_Surface * surface3 = TTF_RenderText_Solid(font, str.c_str(), color);
	SDL_BlitSurface(surface3, NULL, s, &dstrectTime2);
	SDL_FreeSurface(surface3);

	tmp = nw.getNetwork();
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface4 = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface4, NULL, s, &dstrectNW);
	SDL_FreeSurface(surface4);

	str = "ProductName: " + os.getProductName();
	tmp = str;
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface5 = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface5, NULL, s, &dstrectOS);
	SDL_FreeSurface(surface5);

	str = "ProductVersion: " + os.getProductVersion();
	tmp = str;
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface6 = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface6, NULL, s, &dstrectOS2);
	SDL_FreeSurface(surface6);

	str = "BuildVersion: " + os.getBuildVersion();
	tmp = str;
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface7 = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface7, NULL, s, &dstrectOS3);
	SDL_FreeSurface(surface7);

	// str = "HostName: " + host.getHostName();
	// tmp = str;
	// tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface8 = TTF_RenderText_Solid(font, host.getHostName(), color);
	SDL_BlitSurface(surface8, NULL, s, &dstrectHost);
	SDL_FreeSurface(surface8);

	// str = "UserName: " + host.getUserName();
	// tmp = str;
	// tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface9 = TTF_RenderText_Solid(font, host.getUserName(), color);
	SDL_BlitSurface(surface9, NULL, s, &dstrectHost2);
	SDL_FreeSurface(surface9);

	tmp = ram.getRAM();
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface10 = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface10, NULL, s, &dstrectRam);
	SDL_FreeSurface(surface10);

	tmp = pr.getProcesses();
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface11 = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface11, NULL, s, &dstrectProc);
	SDL_FreeSurface(surface11);

	tmp = disk.getDisk();
	tmp2 = tmp.substr(0, tmp.length() - 1);
	SDL_Surface * surface12 = TTF_RenderText_Solid(font, tmp2.c_str(), color);
	SDL_BlitSurface(surface12, NULL, s, &dstrectDisk);
	SDL_FreeSurface(surface12);

	SDL_UpdateWindowSurface(window);
}

void	Sdl::clean()
{
	
	SDL_DestroyWindow(window);
	// SDL_DestroyRenderer(renderer);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Window cleaned" << std::endl;
}