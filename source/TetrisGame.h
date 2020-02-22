// TetrisGame.h

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

// resources
#include "GameScreen.h"
#include "Map.h"

class TetrisGame : public GameScreen
{
    public:
    Action update(SDL_Event* event);
    void logic();
    void setMap(Map* m);
    void addPiece(std::string path, point tlc, std::vector<std::vector<int> > piece);
    void newGame();
    bool moveLeft(std::vector<Entity*>& piece);
    bool moveRight(std::vector<Entity*>& piece);
    bool moveUp(std::vector<Entity*>& piece);
    bool moveDown(std::vector<Entity*>& piece);

    void rotatePiece(std::vector<Entity*>& piece, point rot_in);

    std::vector<std::vector<std::vector<int> > > pieces;

    private:
    Map* m;

    point rot;
    bool hasRotated=false;

    bool getNextPiece;
    int pieceIndex=0;
    int count=0;
};

#endif