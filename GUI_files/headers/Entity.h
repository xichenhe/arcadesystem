// Entity.h

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
	//void setGameObject(SDL_Rect* gameObject_in) { gameObject = gameObject_in; }

	//SDL_Rect* getGameObject() { return gameObject; }

	ArcadeTexture* getGameObjectTexture() { return gameObjectTexture; }

	void setGameObjectTexture(ArcadeTexture* gameObjectTexture_in) 
	{ 
		gameObjectTexture = gameObjectTexture_in;
		xPos = gameObjectTexture->getX();
		yPos = gameObjectTexture->getY();
		width = gameObjectTexture->getW();
		height = gameObjectTexture->getH();
	}

	int getXVelocity() { return xVelocity; }
	int getYVelocity() { return yVelocity; }
	void setYVelocity(int yVelocity_in) { yVelocity = yVelocity_in; }
	void setXVelocity(int xVelocity_in) { xVelocity = xVelocity_in; }

	int getXPos() { return xPos; }
	int getYPos() { return yPos; }
	void setYPos(int yPos_in) { yPos = yPos_in; }
	void setXPos(int xPos_in) { xPos = xPos_in; }

	int getWidth() { return width; }
	int getHeight() { return height; }
	void setHeight(int height_in) { height = height_in; }
	void setWidth(int width_in) { width = width_in; }

	virtual void update(SDL_Event* event) = 0;
	virtual void render(SDL_Renderer* renderer)
	{
		//getGameObjectTexture()->setTexturePosition(getXPos(), getYPos());
		//printf("RENDER entity: %i\n\n", getYPos());
		getGameObjectTexture()->render(renderer); 
	}
	void setState(bool state_in) { state = state_in; }
	bool getState() { return state; }
	
private:
	//std::vector<ArcadeTexture::gridSquare> squares;
	//SDL_Rect* gameObject;
	bool state;
	ArcadeTexture* gameObjectTexture;

	double xVelocity;		
	double yVelocity;

	int xPos;
	int yPos;

	int width;
	int height;

};

#endif


