#ifndef MENU_MOUSE_H
#define MENU_MOUSE_H

/*==============================================================================================#
|                                                                                               |
| Copyright (c) 2019 Karsten Vermeulen. All rights reserved.                                    |
|                                                                                               |
| All code has been written by Karsten Vermeulen as part of the 'Handmade Lite' game engine,    |
| for the purposes of educating other fellow programmers, programming students and anyone else  |
| wishing to learn about game development, C++ and OOP. The structure of the engine, class      |
| design and overall code is constantly under development.                                      |
|                                                                                               |
| Designed to teach. Made from scratch. Built by hand.  						                |
|																							    |
#===============================================================================================#
|																								|
| If you like 'Handmade Lite' and wish to show your support, if you have any questions about    |
| the project, or if you just want to reach out, please find me on the following channels:      |
|																						        |
| Web: http://www.karstenvermeulen.com														    |
| Facebook: https://www.facebook.com/KarstensCorner								                |
| Twitter: https://twitter.com/KarstensCorner													|
| LinkedIn: https://www.linkedin.com/in/karstenvermeulen                                        |
| GitHub: https://github.com/djkarstenv									                        |
|                                                                                               |
#===============================================================================================#
| 'MainMenu' source files last updated in July 2019 									        |
#==============================================================================================*/

#include <map>
#include <vector>
#include "Button.h"
#include "GameObject.h"

class MenuMouse : public GameObject
{

public:

	enum Choice  { NONE = -1 };
	enum Buttons { BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4, BUTTON_5 };
	enum Style   { CENTRE, BOTTOM, LEFT, RIGHT, TOP_LEFT, TOP_RIGHT, BOTTOM_RIGHT };

public:

	MenuMouse(const std::string& filename, Style style = CENTRE, 
		      int buttonTotal = 2, int spacing = 10, int padding = 10);
	virtual ~MenuMouse();

public:

	int GetMenuChoice();

public:

	void SetMenuButton(Buttons button, Button::TextureRow textureRow);

	//int GetMenuOption();
	//void SetMenuButton(int buttonID, );

public:

	virtual void Update();
	virtual bool Draw();

public:

	void Reset();

private:

	bool m_isDirty;

	int m_originX;
	int m_originY;

	int m_spacing;
	int m_padding;

	

	int m_buttonTotal;
	int m_menuChoice;
	int m_menuActive;
	
	

	Style m_style;
	//SDL_Color m_activeColor;
	//SDL_Color m_inactiveColor;

	//std::map<Buttons, Index> m_buttonMap;

	std::string m_spriteID;
	
	std::vector<Button> m_buttons;

	//std::vector<AABB*> m_menuBounds;
	//std::vector<Sprite*> m_menuButtons;

	//int m_menuOptionChoice;
	//int m_menuOptionActive;
	
	//Sprite* m_menuButtons[5];
	/*Sprite* m_menuButton_2;
	Sprite* m_menuButton_3;
	Sprite* m_menuButton_4;
	Sprite* m_menuButton_5;*/

};

#endif