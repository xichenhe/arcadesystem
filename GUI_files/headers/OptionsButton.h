
// OptionsButton.h

// This is a specific type of button
// Abstractly, the OptionsButton class is a way to customize the screen view 
// The main purpose of the OptionsButton is customizability

#ifndef OPTIONS_BUTTON_H
#define OPTIONS_BUTTON_H

#include "Button.h"

class OptionsButton : public Button
{
public:
	// override constructor
	OptionsButton(std::string texturePath_in);

	virtual ~OptionsButton();

	// method to update, more for options button but can be for simple button gifs 
	Action update(SDL_Event* event);

	// method to render the current Buttons
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
		//printf("\n add option\n");
		buttonActionList.push_back(buttonAction_in);
		buttonTextureList.push_back(buttonTexture_in);
	}

	Action* getButtonAction() { return buttonActionList[currentIndex]; }
	ArcadeTexture* getButtonTexture() { return buttonTextureList[currentIndex]; }

	std::vector<ArcadeTexture*>* getButtonTextureList() { return &buttonTextureList; }
	std::vector<Action*>* getButtonActionList() { return &buttonActionList; }
	void setCurrentTextureIndex(int currentButtonIndex_in) { currentIndex = currentButtonIndex_in; }
	int getCurrentButtonIndex() { return currentIndex; }
	ArcadeTexture* getOptionTexture() { return optionTexture; }
	void setOptionTexture(ArcadeTexture* optionTexture_in) { optionTexture = optionTexture_in; }

private:
	// button texture
	ArcadeTexture* optionTexture;

	// holds a vector of arcade textures to iterate through
	std::vector<ArcadeTexture*> buttonTextureList;

	// holds the index of the current button texture
	int currentIndex;

	// holds a vector of button actions
	std::vector<Action*> buttonActionList;
};

#endif
