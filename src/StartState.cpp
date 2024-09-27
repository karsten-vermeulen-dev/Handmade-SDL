#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include "StartState.h"
#include "PlayState.h"
#include "Screen.h"

//======================================================================================================
bool StartState::OnEnter()
{
	image.Load("Backgrounds/Menu_city_1920x1080.png", "Journeys.ogg");
	menu = std::make_unique<MenuKey>("Impact.ttf", MenuKey::Alignment::Bottom, 2, 35, 70);
	menu->SetMenuText(MenuKey::Index::Index_1, "Play game");
	menu->SetMenuText(MenuKey::Index::Index_2, "Quit game");

	return true;
}
//======================================================================================================
GameState* StartState::Update(int deltaTime)
{
	image.PlayMusic();
	menu->Update(deltaTime);

	if (menu->GetMenuChoice() == static_cast<MenuKey::Index>(MenuOption::Play))
	{
		image.StopMusic();
		return new PlayState;
	}

	if (menu->GetMenuChoice() == static_cast<MenuKey::Index>(MenuOption::Quit))
	{
		image.StopMusic();
		return nullptr;
	}

	return this;
}
//======================================================================================================
bool StartState::Render()
{
	image.Render();
	menu->Render();

	//==============================================================================
	//ImGUI UI
	//==============================================================================

	ImGui_ImplSDLRenderer2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
	
	//Add UI code here...

	ImGui::Render();
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), Screen::Instance()->GetRenderer());

	return true;
}
//======================================================================================================
void StartState::OnExit()
{
	//Add shutdown tasks here
}