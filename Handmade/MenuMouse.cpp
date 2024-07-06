#include "InputManager.h"
#include "MenuMouse.h"
#include "ScreenManager.h"
#include "TextureManager.h"

//------------------------------------------------------------------------------------------------------
//constructor that loads and links resources, and sets up the main menu text defaults
//------------------------------------------------------------------------------------------------------
MenuMouse::MenuMouse(const std::string& filename, 
	                 Style style, int buttonTotal, int spacing, int padding)
{

	m_style = style;
	m_isDirty = true;
	
	m_spacing = spacing;
	m_padding = padding;

	//m_buttonWidth = buttonWidth;
	//m_buttonHeight = buttonHeight;

	//m_textureCelWidth = textureCelWidth;
	//m_textureCelHeight = textureCelHeight;

	m_menuActive = NONE;
	m_menuChoice = NONE;

	//first get screen size so that we can set the menu position accordingly
	SDL_Point screenSize = TheScreen::Instance()->GetScreenSize();

	//..
	SDL_Point screenSizeHalf = { screenSize.x / 2, screenSize.y / 2 };

	

	//this will position the buttons dead centre in the middle of the screen
	//X - divide screen width in half and subtract half the width of each button
	//Y - divide screen height in half and subtract half of the menu's button heights
	//if (style == CENTRE)
	//{
	//	m_originX = screenSize.x / 2;
	//	m_posY = (int)((screenSize.y / 2) - (halfButtons * buttonHeight) + spacing));
	//}

	////this will position the buttons in the bottom half of the screen, centered in X
	////X - divide screen width in half and subtract half the width of each button
	////Y - divide screen height in quarters and subtract half of the menu's button heights
	//else if (style == BOTTOM)
	//{
	//	m_posX = screenSize.x / 2;
	//	m_posY = (int)((screenSize.y - screenSize.y / 4) - (buttonTotal / 2.0f * buttonHeight));
	//}

	////this will position the buttons in the bottom half of the screen, aligned on the left
	////X - position the origin on the very left and add on some padding based on passed value
	////Y - divide the screen height in quarters and subtract half of the menu's button heights
	//else if (style == LEFT)
	//{
	//	m_posX += padding;
	//	m_posY = (int)((screenSize.y - screenSize.y / 4) - (buttonTotal / 2.0f * buttonHeight));
	//}

	////this will position the buttons in the bottom half of the screen, aligned on the right
	////X - position the origin on the very right and add on some padding based on passed value
	////Y - divide the screen height in quarters and subtract half of the menu's button heights
	//else if (style == RIGHT)
	//{
	//	m_posX = screenSize.x - padding;
	//	m_posY = (int)((screenSize.y - screenSize.y / 4) - (buttonTotal / 2.0f * buttonHeight));
	//}

	////this will position the buttons in the top left corner of the screen
	////X - position the origin on the very left and add on some padding based on passed value
	////Y - position the origin on the very top and add on some padding based on passed value
	//else if (style == TOP_LEFT)
	//{
	//	m_posX += padding;
	//	m_posY += padding;
	//}

	////this will position the buttons in the top right corner of the screen
	////X - position the origin on the very right and add on some padding based on passed value
	////Y - position the origin on the very top and add on some padding based on passed value
	//else if (style == TOP_RIGHT)
	//{
	//	m_posX = (screenSize.x - padding) - ((buttonWidth + spacing) * (buttonTotal - 1)) - buttonWidth;
	//	m_posY += padding;
	//}

	////this will position the buttons in the bottom right corner of the screen
	////X - position the origin on the very right and add on some padding based on passed value
	////Y - position the origin on the very bottom and add on some padding based on passed value
	//else if (style == BOTTOM_RIGHT)
	//{
	//	m_posX = (screenSize.x - padding) - ((buttonWidth + spacing) * (buttonTotal - 1)) - buttonWidth;
	//	m_posY = screenSize.y - buttonHeight - padding;
	//}

	for (int i = 0; i < buttonTotal; i++)
	{
		
		//m_menuButtons.push_back(new Sprite);
		//m_menuBounds.push_back(new AABB);

		//m_menuBounds[i]->SetDimension(buttonWidth, buttonHeight);

		if (style == CENTRE || style == BOTTOM)
		{

			/*float halfButtons = buttonTotal / 2.0f;

			m_originX = screenSizeHalf.x - (buttonWidth / 2);
			m_originY = screenSizeHalf.y - (halfButtons * buttonHeight) - ((halfButtons - 0.5f) * spacing);

			m_menuBounds[i]->SetPosition(m_originX, m_originY + (i * (buttonHeight + spacing))); */    

		}

		//else if (style == LEFT)
		//{
		//	m_menuBounds[i]->SetPosition(m_posX,                                         //x
		//		                         m_posY + (i * (m_buttonHeight + m_spacing)));   //y
		//}

		//else if (style == RIGHT)
		//{
		//	m_menuBounds[i]->SetPosition(m_posX - m_buttonWidth,                         //x
		//		                         m_posY + (i * (m_buttonHeight + m_spacing)));   //y
		//}

		//else if (style == TOP_LEFT)
		//{
		//	m_menuBounds[i]->SetPosition(m_posX + (i * (m_buttonWidth + m_spacing)),     //x
		//		                         m_posY                                   );     //y
		//}

		//else if (style == TOP_RIGHT)
		//{
		//	m_menuBounds[i]->SetPosition(m_posX + (i * (m_buttonWidth + m_spacing)),     //x
		//		                         m_posY                                   );     //y
		//}

		//else if (style == BOTTOM_RIGHT)
		//{
		//	m_menuBounds[i]->SetPosition(m_posX + (i * (m_buttonWidth + m_spacing)),     //x
		//		                         m_posY                                   );     //y
		//}

	}

	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/" + filename, filename);

	//store sprite resource tag so that we can 
	//use this later on to find the resource
	m_spriteID = filename;

	//..
	m_buttonTotal = buttonTotal;

}

int MenuMouse::GetMenuChoice()
{
	
	return m_menuChoice;

}

void MenuMouse::SetMenuButton(Buttons button, Button::TextureRow textureRow)
{
//
//	m_menuButtons[button]->SetTexture(m_spriteID);
//	m_menuButtons[button]->SetTextureDimension(TOTAL_STATES, m_buttonTotal, m_textureCelWidth, m_textureCelHeight);
//	m_menuButtons[button]->SetSpriteDimension(m_buttonWidth, m_buttonHeight);
//	m_menuButtons[button]->SetTextureCel(INACTIVE, index);
//
//	m_buttonMap[button] = index;
//
}

//------------------------------------------------------------------------------------------------------
//function that updates the main menu text on screen
//------------------------------------------------------------------------------------------------------
void MenuMouse::Update()
{

	////reset!
	//m_menuActive = NONE;

	////first make all buttons inactive
	//for (size_t i = 0; i < m_menuButtons.size(); i++)
	//{
	//	m_menuButtons[i]->SetTextureCel(INACTIVE, m_buttonMap[(Buttons)i]);
	//}

	//for (size_t i = 0; i < m_menuBounds.size(); i++)
	//{

	//	if (TheInput::Instance()->IsMouseColliding(*m_menuBounds[i]))
	//	{
	//		m_menuActive = i;

	//		if (TheInput::Instance()->GetLeftButtonState() == InputManager::DOWN)
	//		{
	//			m_menuChoice = i;
	//		}

	//		//set active button
	//		if (m_menuActive != NONE)
	//		{
	//			m_menuButtons[m_menuActive]->SetTextureCel(ACTIVE, m_buttonMap[(Buttons)m_menuActive]);
	//		}

	//	}

	//}

}
//------------------------------------------------------------------------------------------------------
//function that renders the main menu text on screen
//------------------------------------------------------------------------------------------------------
bool MenuMouse::Draw()
{

	//loop through all menu items and position them based on the 'm_posX' and 'm_posY' origin
	//check what menu style is set so that we can determine where on-screen to render the buttons

	//for (size_t i = 0; i < m_menuButtons.size(); i++)
	//{

	//	if (m_style == CENTRE || m_style == BOTTOM)
	//	{
	//		//m_menuButtons[i]->Draw(m_posX - (m_buttonWidth / 2.0f),                     //x
	//		//	                   m_posY + (i * (m_buttonHeight + m_spacing)));     //y

	//		m_menuButtons[i]->Draw(m_originX, m_originY + (i * (m_buttonHeight + m_spacing)));

	//	}

		//else if (m_style == LEFT)
		//{
		//	m_menuButtons[i]->Draw(m_posX,                                           //x
		//		                   m_posY + (i * (m_buttonHeight + m_spacing)));     //y
		//}

		//else if (m_style == RIGHT)
		//{
		//	m_menuButtons[i]->Draw(m_posX - m_buttonWidth,                           //x
		//		                   m_posY + (i * (m_buttonHeight + m_spacing)));     //y
		//}

		//else if (m_style == TOP_LEFT)
		//{
		//	m_menuButtons[i]->Draw(m_posX + (i * (m_buttonWidth + m_spacing)),       //x
		//		                   m_posY                                   );       //y
		//}

		//else if (m_style == TOP_RIGHT)
		//{
		//	m_menuButtons[i]->Draw(m_posX + (i * (m_buttonWidth + m_spacing)),       //x
		//		                   m_posY                                   );       //y
		//}

		//else if (m_style == BOTTOM_RIGHT)
		//{
		//	m_menuButtons[i]->Draw(m_posX + (i * (m_buttonWidth + m_spacing)),       //x
		//		                   m_posY                                   );       //y
		//}

	//}

	return true;

}
//------------------------------------------------------------------------------------------------------
//function that resets the menu back to its default
//------------------------------------------------------------------------------------------------------
void MenuMouse::Reset()
{

	m_menuActive = NONE;
	m_menuChoice = NONE;

}
//------------------------------------------------------------------------------------------------------
//destructor that unloads font resource from memory
//------------------------------------------------------------------------------------------------------
MenuMouse::~MenuMouse()
{

	//for (size_t i = 0; i < m_menuButtons.size(); i++)
	//{
	//	delete m_menuButtons[i];
	//}

	//for (size_t i = 0; i < m_menuBounds.size(); i++)
	//{
	//	delete m_menuBounds[i];
	//}

	//m_menuButtons.clear();
	//m_menuBounds.clear();

	TheTexture::Instance()->
	UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, m_spriteID);

}