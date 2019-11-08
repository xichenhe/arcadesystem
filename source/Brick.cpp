#include "Brick.h"



Brick::Brick(bool state_in, int xVel_in, int yVel_in, int xPos_in, int yPos_in, int w_in, int h_in)

{

	setState(state_in);

	setXVelocity(xVel_in);

	setYVelocity(yVel_in);

	setHeight(h_in);

	setWidth(h_in);

	setXPos(xPos_in);

	setYPos(yPos_in);

}



void Brick::update(SDL_Event* event) {}