// Entity.h

// DESCRIPTION
// This is an abstract class for a generic game object

#ifndef ENTITY_H
#define ENTITY_H

#include "ArcadeTexture.h"
#include "SDL.h"

class Entity
{
public:
	~Entity()
	{
		delete gameObjectTexture;
	}

	ArcadeTexture* getGameObjectTexture() { return gameObjectTexture; }

	// ACCESSORS
	int getXVelocity() { return xVelocity; }
	int getYVelocity() { return yVelocity; }
	int getXPos() { return xPos; }
	int getYPos() { return yPos; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	bool getState() { return state; }

	// MUTATORS
	void setState(bool state_in) { state = state_in; }
	void setXVelocity(int xVelocity_in) { xVelocity = xVelocity_in; }
	void setYVelocity(int yVelocity_in) { yVelocity = yVelocity_in; }
	void setYPos(int yPos_in);
	void setXPos(int xPos_in);
	void setHeight(int height_in) { height = height_in; }
	void setWidth(int width_in) { width = width_in; }
	void setGameObjectTexture(ArcadeTexture* gameObjectTexture_in);

	virtual void update(SDL_Event* event) = 0;
	virtual void render(SDL_Renderer* renderer);
	
private:
	bool state;
	ArcadeTexture* gameObjectTexture = nullptr;

	double xVelocity;		
	double yVelocity;

	int xPos;
	int yPos;

	int width;
	int height;
};

#endif