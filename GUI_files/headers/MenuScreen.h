// menuScreen.h

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
	// Override default constructor, default parameter in case none passed in
	MenuScreen();

	// override destructor
	virtual ~MenuScreen();

	// method to update, returns an Action struct, takes in the input as parameter
	Action update(SDL_Event* event);

	// method to render the current Screen
	void render(SDL_Renderer* renderer);

	// method to add a button to the button list
	void addButtonToScreen(Button* button_in) 
	{
		buttonList.push_back(button_in); 
	}

	// method to get the vector buttonList
	std::vector<Button*>* getButtonList() { return &buttonList; }

	void inputText(SDL_Event* e);

	
private:
	// has a vector of buttons to updateand render
	std::vector<Button*> buttonList;
};

#endif

