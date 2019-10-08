// SimpleButton.h

//DESCRIPTION
// This is a specific type of button.
// In general, the SimpleButton is a way to move to new screens and nodes. 


#ifndef SIMPLE_BUTTON_H
#define SIMPLE_BUTTON_H

#include "Button.h"

class SimpleButton : public Button
{
public:
	SimpleButton();

	// override constructor, gets called when 'createSimpleButton' calls new on SimpleButton, set all values to defaults if none given
	SimpleButton(std::string texturePath_in);

	// override destructor
	virtual ~SimpleButton();

	void setButtonPosition(int x_in, int y_in)
	{
		setX(x_in);
		setY(y_in);
		if (buttonTexture != nullptr)
		{
			buttonTexture->setPosition(x_in, y_in);
		}
	}

	void setButtonSize(int w_in, int h_in)
	{
		setWidth(w_in);
		setHeight(h_in);
		if (buttonTexture != nullptr)
		{
			buttonTexture->setSize(w_in, h_in);
		}
	}

	// update method is a pure virtual function that was inherited and must be implemented
	Action update(SDL_Event* event);

	// render method is a pure virtual function that was inherited and must be implemented
	void render(SDL_Renderer* renderer);

	// ----------------------------------------- Accessors and mutators ---------------------------------------
	// NOTES: only needed for the private member variables that the SimpleButton class added on top of the Button class

	// ACCESSORS

	// method to get the button's action which is the enum
	Action* getButtonAction() { return buttonAction; }

	// method to get the texture of the button, used in the render method
	ArcadeTexture* getButtonTexture() { return buttonTexture; }

	// MUTATORS

	void setButtonAction(Action* buttonAction_in) 
	{ 
		buttonAction = buttonAction_in; 
		if (buttonAction_in == nullptr)
		{
			//printf("WARNING! Setting simpleButton's action to a nullptr");
		}
	}

	void setButtonTexture(ArcadeTexture* buttonTexture_in)
	{ 
		buttonTexture = buttonTexture_in; 
		if (buttonTexture_in == nullptr)
		{
			//printf("WARNING! Setting simpleButton's texture to a nullptr");
		}
	}

private:
	// has a pointer to a button's action
	Action* buttonAction;

	// has a pointer to the button's texture which can be configured
	ArcadeTexture* buttonTexture;
};

#endif
