// OptionsButton.cpp

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

Action OptionsButton::update(SDL_Event* event)
{
	Action newAction = { DO_NOTHING, nullptr };
	
	// only update the button texture if a mouse event happens
	if (event && (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN))
	{
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
		else // Mouse inside button
		{
			optionTexture->setSelected(true);
			if(event->type == SDL_MOUSEBUTTONDOWN)
			{
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
			}
		}
	}
	return newAction;
}

// method to render the current Buttons
void OptionsButton::render(SDL_Renderer* renderer)
{
	optionTexture->render(renderer);
	buttonTextureList[currentIndex]->render(renderer);
}

