#include "Application.h"

#include <SDL.h>
#include <SDL_syswm.h> // for evil

#include <stdio.h>

namespace
{
	static const char WINDOW_TITLE[] = "Hotdog Engine";
	static const int WINDOW_WIDTH = 640;
	static const int WINDOW_HEIGHT = 480;
}

Application::Application()
	: m_windowHandle(NULL)
{
	// Create SDL window
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	m_sdlWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_sdlWindow == NULL)
	{
		fprintf(stderr, "Could not create window. Erorr: %s\n", SDL_GetError());
		return;
	}

	// Steal a handle to the window to give D3D11
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(m_sdlWindow, &wmInfo);
	m_windowHandle = wmInfo.info.win.window;
}

Application::~Application()
{
	// Destroy the window and quit SDL.
	if (m_sdlWindow != NULL)
	{
		SDL_DestroyWindow(m_sdlWindow);
	}
	SDL_Quit();
}

void Application::Run()
{
	uint32_t lastTicks = SDL_GetTicks();

	bool running = true;
	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
		}
	}
}