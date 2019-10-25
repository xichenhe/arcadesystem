#include "GameScreen.h"

void GameScreen::restartGame()
{
	gameState = true;
	isNewGame = true;
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
		return newAction;
	}
	else if ((*event).key.keysym.sym == SDLK_q)
	{
		newAction = { MOVE_NODES, parentNode };
		return newAction;
	}
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
}
