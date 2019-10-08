#include "GameScreen.h"

void GameScreen::restartGame()
{
	gameState = true;
	isNewGame = true;
}
void updateGrid()
{

}

void GameScreen::loadGrid()
{
	for (int i = 0; i < entities.size(); i++)
	{
		// first get the position of the top left corner in the grid
		// ex: (5,5) is at position 0,0 so add it to that position in the grid
		int gridTLX = entities[i]->getXPos() / side;
		int gridTLY = entities[i]->getYPos() / side;
		//printf("GRID TLX: %i\n", gridTLX);
		//printf("GRID TLY: %i\n", gridTLY);
		gridContainer[gridTLX][gridTLY].push_back(entities[i]);

		// then find the far right and bottom left
		int gridTRX = (entities[i]->getXPos() + entities[i]->getWidth() + side - 1) / side - 1;
		int gridBLY = (entities[i]->getYPos() + entities[i]->getHeight() + side - 1) / side - 1;
		//printf("GRID TRX: %i\n", gridTRX);
		//printf("GRID BLY: %i\n", gridBLY);
		for (int col = gridTLX; col <= gridTRX; col++)
		{
			for (int row = gridTLY; row <= gridBLY; row++)
			{
				gridContainer[col][row].push_back(entities[i]);
				//printf("COL, ROW: %i,%i\n", col, row);
			}
		}
	}
}

// method to update, returns an Action struct, takes in the input as parameter
Action GameScreen::update(SDL_Event* event)
{
	Action newAction = { DO_NOTHING, nullptr };
	for (int i = 0; i < movingEntities.size(); i++)
	{
		movingEntities[i]->update(event);
	}
	if (!event)
	{
		newAction = { DO_NOTHING, nullptr };
	}
	else if ((*event).key.keysym.sym == SDLK_q)
	{
		newAction = { MOVE_NODES, parentNode };
	}
	
	return newAction;
}

// method to render the current Screen
void GameScreen::render(SDL_Renderer* renderer)
{
	// the screen first renders all its textures
	for (int i = 0; i < getArcadeTextureList()->size(); i++)
	{
		(*getArcadeTextureList())[i]->render(renderer);
	}

	// the screen then renders all its buttons
	for (int i = 0; i < getEntities()->size(); i++)
	{
		if ((*getEntities())[i]->getState() == false)
			continue;
		(*getEntities())[i]->render(renderer);
	}
	// set the current button's selector texture destination to the current button's destination
	// we need to do this because some buttons share a selector texture so we must reposition it
}




