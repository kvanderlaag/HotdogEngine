#pragma once

#include <SDL.h>
#include <Windows.h>

class Application
{
public:
	Application();
	virtual ~Application();
	
	void Run();
	inline bool HasWindowHandle() const
	{
		return m_windowHandle != nullptr;
	}
private:
	HWND m_windowHandle;
	SDL_Window* m_sdlWindow;
};