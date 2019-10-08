// Button.h

// DESCRIPTION:
// This is a abstract base Button class
// In general, the Button class represents an entity in the Screen Class 
// The main purpose of the Button is to provide the user with an interface to the screen


#ifndef BUTTON_H
#define BUTTON_H

// Buttons need access to SDL resources, have actions, have textures, vectors, and strings
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
		SELECTOR
	};

	enum buttonColor
	{
		RED = 0,
		GREEN,
		BLUE
	};

	virtual ~Button() {}
	// We don't need a constructor because derived classes have access to the mutator methods and will initialize the private member variables

	// UPDATE:
	// This is a method that must be overridden by derived button classes and is where events will be handled
	virtual Action update(SDL_Event* event) = 0;

	// RENDER:
	// This is a method that must be overriden by derived butotn classes and is where buttons will render themselves
	virtual void render(SDL_Renderer* renderer) = 0;


	// ----------------------------------------- Accessors and mutators ---------------------------------------

	// NOTE: the button's x, y, width, and height are actually the x, y, width, and height of the button texture and
	// these methods allow the user to change and access these values without having to directly interact with textures

	// ACCESSORS

	// method to get a button’s x position
	int getX() { return xPos; }

	// method to get a button’s y position
	int getY() { return yPos; }

	// method to get a button’s width
	int getWidth() { return width; }

	// method to get a button’s height
	int getHeight() { return height; }

	// method to get a Button’s texture path, either an image or a font
	std::string getButtonTexturePath() { return texturePath; }

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

	// method to set a button’s x position
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

	// method to set a button’s y position
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

	// method to set a button’s width
	void setWidth(int width_in)
	{
		if (width_in < 0)
		{
			width = defaultTextureWidth;
			printf("ERROR! Button width: '%i' is invalid.", width_in);
		}
		else
		{
			width = width_in;
		}
	}

	// method to set a button’s height
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

	// method to set a button’s image path
	void setTexturePath(std::string filePath_in) 
	{
		// this is checked at the texture level in 'loadFromFile'
		texturePath = filePath_in; 
	}

	// there is no general method to set a button's action because simpleButton and optionsButton handle this differently

private:

	// x position
	int xPos;

	// y position
	int yPos;

	// width
	int width;

	// height
	int height;

	// file path to texture of button for rendering, either an image or text
	std::string texturePath;
};

#endif
