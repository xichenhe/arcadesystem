// Screen.h

// DESCRIPTION
// This is the flesh of the arcade system and where all the action occurs
// Abstractly, the Screen object represents a state in the tree that can be executed
// The main purpose of the Screen is to provide a point of execution


// Note that only menu screens include button.h

#ifndef SCREEN_H
#define SCREEN_H

#include "ArcadeTexture.h"
#include "Action.h"
#include "Button.h"

class Screen
{
public:
	virtual ~Screen() {};

	virtual Action update(SDL_Event* event) = 0;

	virtual void render(SDL_Renderer* renderer) = 0;

	std::vector<ArcadeTexture*>& getArcadeTextureList() { return arcadeTextureList; }

	void addTextureToScreen(ArcadeTexture* arcadeTexture_in) { arcadeTextureList.push_back(arcadeTexture_in); }
	
private:

	// has a vector of textures to render to the screen, not including buttons
	std::vector<ArcadeTexture*> arcadeTextureList;
};

#endif