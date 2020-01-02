// SimpleButton.h

// DESCRIPTION
// This is a specific type of button.
// In general, the SimpleButton is a way to move to new screens and nodes. 


#ifndef SIMPLE_BUTTON_H
#define SIMPLE_BUTTON_H

#include "Button.h"

class SimpleButton : public Button
{
public:
	SimpleButton();

	SimpleButton(std::string texturePath_in);

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

	Action update(SDL_Event* event);

	void render(SDL_Renderer* renderer);


	// ACCESSORS
	Action* getButtonAction() { return buttonAction; }

	ArcadeTexture* getButtonTexture() { return buttonTexture; }

	// MUTATORS
	void setButtonAction(Action* buttonAction_in) 
	{ 
		buttonAction = buttonAction_in; 
	}

	void setButtonTexture(ArcadeTexture* buttonTexture_in)
	{ 
		buttonTexture = buttonTexture_in; 
	}

private:
	Action* buttonAction;

	ArcadeTexture* buttonTexture;
};

#endif
