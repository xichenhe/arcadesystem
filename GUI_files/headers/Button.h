// Button.h

// DESCRIPTION:
// This is a abstract base class for a generic button.
// A button object is how the user interacts with a Menu Screen.


#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"
#include "Config.h"
#include "Action.h"
#include "ArcadeTexture.h"
#include <vector>
#include <string>

class Button
{
public:

	// All button textures have a default state and a selected state
	enum buttonImage
	{
		DEFAULT = 0,
		SELECTED
	};

	// We don't need a constructor because derived classes 
	//have access to the mutator methods and will initialize
	// the private member variables

	// DESTRUCTOR
	virtual ~Button() {}

	// This is a function that must be overridden by 
	// derived button classes and is where events are handled
	virtual Action update(SDL_Event* event) = 0;

	// This is a function that must be overriden by derived 
	// button classes and is where buttons will render themselves
	virtual void render(SDL_Renderer* renderer) = 0;


	// ----------------------------------------- Accessors and mutators ---------------------------------------

	// NOTE: the button's x, y, width, and height are actually the x, y, width, and height of the button texture and
	// these methods allow the user to change and access these values without having to directly interact with textures

	// ACCESSORS
	int getX() { return xPos; }

	int getY() { return yPos; }

	int getWidth() { return width; }

	int getHeight() { return height; }

	// method to get a button's action type, this is a pure virtual function because different buttons may return their actions
	// in different ways. For example, an options buttons must get its action from a vector because can hold multiplpe actions
	virtual Action* getButtonAction() = 0;

	// method to get the button's current texture, this is a pure virtual function for the same reason as getButtonAction
	virtual ArcadeTexture* getButtonTexture() = 0;

	// MUTATORS
	// We have private member variables to control how the user changes and accesses the member variables. For the accessors
	// it may be trivial, just return the variable (unless it is more involved such as with get button action) However, for
	// mutators, we want to prevent the user from changing the member variables to some invalid values such as a negative number
	// so we check for valid input and print an error to the console if it is invalid and set the variable to a default value.

	void setX(int x_in) 
	{ 
		if (x_in < 0 || x_in > windowWidth)
		{
			xPos = 0;
			printf("ERROR! Button xPos: '%i' is outside of window bounds.", x_in);
		}
		else
		{
			xPos = x_in;
		}
	}

	void setY(int y_in)
	{
		if (y_in < 0 || y_in > windowHeight)
		{
			yPos = 0;
			printf("ERROR! Button yPos: '%i' is outside of window bounds.", y_in);
		}
		else
		{
			yPos = y_in;
		}
	}

	void setWidth(int width_in)
	{
		if (width_in < 0)
		{
			width = 0;
			printf("ERROR! Button width: '%i' is invalid.", width_in);
		}
		else
		{
			width = width_in;
		}
	}

	void setHeight(int height_in)
	{
		if (height_in < 0)
		{
			height = 0;
			printf("ERROR! Button height: '%i' is invalid.", height_in);
		}
		else
		{
			height = height_in;
		}
	}

	void setTexturePath(std::string filePath_in) 
	{
		// this is checked at the texture level in 'loadFromFile'
		texturePath = filePath_in; 
	}

private:

	int xPos;
	int yPos;

	int width;
	int height;

	// file path to texture of button
	std::string texturePath;
};

#endif