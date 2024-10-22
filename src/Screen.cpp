#include <SDL_syswm.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include "Screen.h"
#include "Utility.h"

//======================================================================================================
Screen* Screen::Instance()
{
	static Screen* screenObject = new Screen();
	return screenObject;
}
//======================================================================================================
HWND Screen::GetWindowHandle()
{
	return windowHandle;
}
//======================================================================================================
SDL_Window* Screen::GetWindow()
{
	return window;
}
//======================================================================================================
SDL_Renderer* Screen::GetRenderer()
{
	return renderer;
}
//======================================================================================================
const SDL_Point& Screen::GetResolution()
{
	return resolution;
}
//======================================================================================================
void Screen::SetMousePosition(int x, int y)
{
	SDL_WarpMouseInWindow(window, x, y);
}
//======================================================================================================
void Screen::SetClearColor(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}
//======================================================================================================
bool Screen::Initialize(const std::string& windowTitle, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"Error initializing SDL.", Utility::Severity::Failure);
		return false;
	}

	Uint32 screenFlag = (fullscreen) ? SDL_WINDOW_FULLSCREEN : 0;

	window = SDL_CreateWindow(windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height, screenFlag);

	if (!window)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"Game window could not be created.", Utility::Severity::Failure);
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		Utility::Log(Utility::Destination::WindowsMessageBox,
			"Renderer could not be created.", Utility::Severity::Failure);
		return false;
	}

	//Use this to get Windows handle on game window for
	//use with Windows message boxes and other stuff 
	SDL_SysWMinfo systemInfo;
	SDL_VERSION(&systemInfo.version);
	SDL_GetWindowWMInfo(window, &systemInfo);
	windowHandle = systemInfo.info.win.window;

	resolution = { width, height };

	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);
	
	return true;
}
//======================================================================================================
void Screen::Clear()
{
	SDL_RenderClear(renderer);
}
//======================================================================================================
void Screen::Present()
{
	SDL_RenderPresent(renderer);
}
//======================================================================================================
void Screen::Shutdown()
{
	ImGui_ImplSDLRenderer2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}