// GameScreen.cpp

#include "GameScreen.h"

GameScreen:: ~GameScreen()
{
	for (int i = 0; i < getArcadeTextureList().size(); i++)
	{
		if (getArcadeTextureList()[i] != nullptr)
		{
			delete getArcadeTextureList()[i];
			getArcadeTextureList()[i] = nullptr;
		}
	}
	for (int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
}

void GameScreen::restartGame()
{
	gameState = true;
	isNewGame = true;
}

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
	for (int i = 0; i < getArcadeTextureList().size(); i++)
	{
		getArcadeTextureList()[i]->render(renderer);
	}

	// the screen then renders all its buttons
	for (int i = 0; i < getEntities().size(); i++)
	{
		if (getEntities()[i]->getState() == false)
			continue;
		getEntities()[i]->render(renderer);
	}
}
