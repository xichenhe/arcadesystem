#include "OptionsButton.h"

// override constructor
OptionsButton::OptionsButton(std::string texturePath_in)
{
	setTexturePath(texturePath_in);
	optionTexture = nullptr;
	currentIndex = 0;
}


OptionsButton::~OptionsButton()
{
	for (int i = 0; i < buttonTextureList.size(); i++)
	{
		delete buttonTextureList[i];
	}
	for (int i = 0; i < buttonActionList.size(); i++)
	{
		delete buttonActionList[i];
	}
	delete optionTexture;
}
// method to update

// if the event is a tab just return move button selector
// if event is key press enter, this button's action and action parameter are returned
Action OptionsButton::update(SDL_Event* event)
{
	// at the end we return newAction. We initialize it to do nothing and change it based on the event
	Action newAction = { DO_NOTHING, nullptr };

	//Get mouse position
	int x, y;
	SDL_GetMouseState(&x, &y);

	//Check if mouse is in button
	bool inside = true;

	//Mouse is left of the button
	if (x < getX())
	{
		inside = false;
	}
	//Mouse is right of the button
	else if (x > getX() + getWidth())
	{
		inside = false;
	}
	//Mouse above the button
	else if (y < getY())
	{
		inside = false;
	}
	//Mouse below the button
	else if (y > getY() + getHeight())
	{
		inside = false;
	}

	//Mouse is outside button
	if (!inside)
	{
		optionTexture->setSelected(false);
	}
	else
	{
		optionTexture->setSelected(true);
	}

	if (event && (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN))
	{
		if (!inside)
		{
			optionTexture->setSelected(false);
		}
		else
		{
			//Set mouse over sprite
			switch (event->type)
			{
			case SDL_MOUSEMOTION:
				optionTexture->setSelected(true);
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (currentIndex + 1 < buttonActionList.size())
				{
					currentIndex += 1;
					newAction = *buttonActionList[currentIndex];
				}
				else
				{
					currentIndex = 0;
					newAction = *buttonActionList[currentIndex];
				}
				break;
				/*case SDL_MOUSEBUTTONUP:
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					break;*/
			}
		}
	}
	return newAction;
}

// method to render the current Buttons
void OptionsButton::render(SDL_Renderer* renderer)
{
	//printf("current button texture   %p \n", buttonTextureList[currentIndex]);
	optionTexture->render(renderer);
	buttonTextureList[currentIndex]->render(renderer);
}

