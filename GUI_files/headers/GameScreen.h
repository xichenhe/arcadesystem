// GameScreen.h

#ifndef GAME_SCREEN
#define GAME_SCREEN

#include "Screen.h"
#include "Entity.h"
class GameScreen : public Screen
{
public:

	virtual ~GameScreen()
	{
		for (int i = 0; i < getArcadeTextureList()->size(); i++)
		{
			if ((*getArcadeTextureList())[i] != nullptr)
			{
				delete (*getArcadeTextureList())[i];
				(*getArcadeTextureList())[i] = nullptr;
			}

		}
		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}
	}

	virtual void newGame() = 0;

	virtual Action update(SDL_Event* event);

	// method to render the current Screen
	virtual void render(SDL_Renderer* renderer);

	std::vector<Entity*>* getEntities() { return &entities; }
	void addEntity(Entity* entity_in) { entities.push_back(entity_in); }

	std::vector<Entity*>* getMovingEntities() { return &movingEntities; }
	void addMovingEntity(Entity* movingEntity_in) { movingEntities.push_back(movingEntity_in); }

	void setParentNode(void* parentNode_in) { parentNode = parentNode_in; }
	void* getParentNode() { return parentNode; }

	void setPauseScreen(void* pauseScreen_in) { pauseScreen = pauseScreen_in; }
	void* getPauseScreen() { return pauseScreen; }

	void setGameOverScreen(void* gameOverScreen_in) { gameOverScreen = gameOverScreen_in; }
	void* getGameOverScreen() { return gameOverScreen; }

	void setGameState(bool gameState_in) { gameState = gameState_in; }
	bool getgameState() { return gameState; }

	void setisNewGame(bool isNewGame_in) { isNewGame = isNewGame_in; }
	bool getIsNewGame() { return isNewGame; }

	void restartGame();

	struct playerScore
	{
		std::string gameName;
		std::string name;
		int score;
	};
private:
	std::vector<Entity*> entities;
	std::vector<Entity*> movingEntities;

	void* parentNode;

	void* pauseScreen;
	void* gameOverScreen;

	bool gameState;
	bool isNewGame;
};
#endif

