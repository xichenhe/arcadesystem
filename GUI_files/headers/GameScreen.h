// GameScreen.h

// DESCRIPTION
// This is an abstract class for a generic game screen.
// Game screens are basically just games.

#ifndef GAME_SCREEN
#define GAME_SCREEN

#include "Screen.h"
#include "Entity.h"

class GameScreen : public Screen
{
public:

	virtual ~GameScreen();

	virtual void newGame() = 0;

	virtual Action update(SDL_Event* event);

	virtual void render(SDL_Renderer* renderer);

	std::vector<Entity*>& getEntities() { return entities; }
	void addEntity(Entity* entity_in) { entities.push_back(entity_in); }

	std::vector<Entity*>& getMovingEntities() { return movingEntities; }
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

	void submitScore(SDL_Event* e, SDL_Renderer* ren);

	struct playerScore
	{
		std::string gameName;
		std::string name;
		int score;
	};

	bool CompareEntries(const playerScore& left, const playerScore& right) 
	{
		return left.score > right.score;
	}

	std::string gameName;
	int gameScore;
	ArcadeTexture* gameScoreTexture;
	
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