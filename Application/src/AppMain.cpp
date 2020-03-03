//#define COBJMACROS
#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>

#include "Application.h"

int main(int argc, char** argv)
{
	// Set the working directory if one is specified.
	if (argc >= 3 && strcmp(argv[1], "-wkdir") == 0)
	{
		WCHAR wsPath[255];
		mbstowcs(wsPath, argv[1], strlen(argv[1]) + 1);
		SetCurrentDirectory(wsPath);
	}

	// Create an application
	Application app;

	// If it failed to create a window, exit.
	if (!app.HasWindowHandle())
	{
		return -1;
	}

	// App init here for d3d11? Maybe just RAII this; if it fails, it fails.

	// Run the application.
	app.Run();

	// Cleanup is handled by App's destructor.
	return 0;
}