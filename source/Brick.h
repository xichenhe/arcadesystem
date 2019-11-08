#ifndef BRICK_H

#define BRICK_H

#include "Entity.h"

class Brick : public Entity

{

public:

	Brick(bool state_in = false, int xVel_in = 0, int yVel_in = 0, int xPos_in = 0, int yPos_in = 0, int w_in = 100, int h_in = 100);

	void update(SDL_Event* event);

};

#endif