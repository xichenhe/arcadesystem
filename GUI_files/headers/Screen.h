// Screen.h

// This is the “flesh” of the virtual arcade system and where all the action occurs
// Abstractly, the Screen object represents a state in the tree that can be executed
// The main purpose of the Screen is to provide a point of execution


// Note that only menu screens include “button.h” and only game screens include “game.h”

#ifndef SCREEN_H
#define SCREEN_H

#include "ArcadeTexture.h"
#include "Action.h"
#include "Button.h"

class Screen
{
public:
	virtual ~Screen() {};

	// method to update, returns a command struct, takes in the input as parameter
	virtual Action update(SDL_Event* event) = 0;

	// method to render the current Screen
	virtual void render(SDL_Renderer* renderer) = 0;

	// method to get the vector arcadeTextureList
	std::vector<ArcadeTexture*>* getArcadeTextureList() { return &arcadeTextureList; }

	// add texture to arcade texture list
	void addTextureToScreen(ArcadeTexture* arcadeTexture_in) { arcadeTextureList.push_back(arcadeTexture_in); }
	
private:

	// has a vector of textures to render to the screen, not including buttons
	std::vector<ArcadeTexture*> arcadeTextureList;

};

#endif