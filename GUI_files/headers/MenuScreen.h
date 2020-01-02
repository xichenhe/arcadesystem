// menuScreen.h

// DESCRIPTION
// This is one specific type of screen that inherits from the Screen base class
// Abstractly, the menuScreen class represents a collection of Buttons 
// The main purpose of the menuScreen is to provide a point of transition


#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "Button.h"
#include "Screen.h"	
#include <string>
#include <vector>

class MenuScreen : public Screen
{
public:

	MenuScreen();

	virtual ~MenuScreen();

	Action update(SDL_Event* event);

	void render(SDL_Renderer* renderer);

	void addButtonToScreen(Button* button_in) 
	{
		buttonList.push_back(button_in); 
	}

	std::vector<Button*>& getButtonList() { return buttonList; }

	void inputText(SDL_Event* e);

private:
	std::vector<Button*> buttonList;
};

#endif