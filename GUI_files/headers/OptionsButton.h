
// OptionsButton.h

// DESCRIPTION
// This is a specific type of button
// Used to change things like music and sound

#ifndef OPTIONS_BUTTON_H
#define OPTIONS_BUTTON_H

#include "Button.h"

class OptionsButton : public Button
{
public:
	OptionsButton(std::string texturePath_in);

	virtual ~OptionsButton();
 
	Action update(SDL_Event* event);

	void render(SDL_Renderer* renderer);

	void setButtonPosition(int x_in, int y_in)
	{
		setX(x_in);
		setY(y_in);
		if (optionTexture != nullptr)
		{
			optionTexture->setPosition(x_in, y_in);
		}
	}

	void addOption(Action* buttonAction_in, ArcadeTexture* buttonTexture_in)
	{
		buttonActionList.push_back(buttonAction_in);
		buttonTextureList.push_back(buttonTexture_in);
	}

	Action* getButtonAction() { return buttonActionList[currentIndex]; }
	ArcadeTexture* getButtonTexture() { return buttonTextureList[currentIndex]; }

	std::vector<ArcadeTexture*>* getButtonTextureList() { return &buttonTextureList; }
	std::vector<Action*>* getButtonActionList() { return &buttonActionList; }
	int getCurrentButtonIndex() { return currentIndex; }
	ArcadeTexture* getOptionTexture() { return optionTexture; }

	void setCurrentTextureIndex(int currentButtonIndex_in) { currentIndex = currentButtonIndex_in; }
	void setOptionTexture(ArcadeTexture* optionTexture_in) { optionTexture = optionTexture_in; }

private:
	// the button itself
	ArcadeTexture* optionTexture;

	// the button "states"
	std::vector<ArcadeTexture*> buttonTextureList;

	// holds the index of the current button texture
	int currentIndex;

	std::vector<Action*> buttonActionList;
};

#endif
