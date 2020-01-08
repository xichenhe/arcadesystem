// Map.h

#include "Map.h"

Map::Map(int sideSize_in, int xDim_in, int yDim_in, SDL_Renderer* ren_in)
{
    ren = ren_in;
    sideSize = sideSize_in;
    xDim = xDim_in;
    yDim = yDim_in;

    // initializing squares
    std::vector<Tile*> v; // temporary vector that will be copied

    // number of elements per vector (x)
    for(int col = 0; col < xDim; col++)
    {
        v.push_back(nullptr);
    }
    // number of vectors (y)
    for(int row = 0; row < yDim; row++)
    {
        squares.push_back(v); // push_back creates a copy
    }
    // squares[0][0] means get the first vector and the first element in that vector
    // the first coord is the vector# and the second coord is the index
    
    for(int row = 0; row < yDim; row++)
    {
        for(int col = 0; col < xDim; col++)
        {
            Tile* newTile = new Tile();
            newTile->setState(false);
            newTile->setWidth(sideSize);
            newTile->setHeight(sideSize);
            squares[row][col] = newTile;
        }
    }
}

// this function is used to add things to the map
void Map::config(std::string path, point tlc, std::vector<std::vector<int> > squares_in, bool canMove)
{
    if(tlc.x > squares[0].size())
    {
        printf("TLC x coordinate %i out of range\n", tlc.x);
        return;
    }
    if(tlc.y > squares.size())
    {
        printf("TLC y coordinate %i out of range\n", tlc.y);
        return;
    }
    for(int row = 0; row < squares_in.size(); row++)
    {
        for(int col = 0; col < squares_in[row].size(); col++)
        {
            if(squares_in[row][col] == 1)
            {
                squares[tlc.y+row][tlc.x+col]->setState(false);
                ArcadeTexture* newArcadeTexture = new ArcadeTexture;
                newArcadeTexture->setRenderer(ren);
                newArcadeTexture->loadFromFile(path);
                newArcadeTexture->isEntireDestination = false;
                newArcadeTexture->setSize(squares[row][col]->getWidth(), squares[row][col]->getHeight());
                newArcadeTexture->setPosition(sideSize*(tlc.x+col), sideSize*(tlc.y+row));
                squares[tlc.y+row][tlc.x+col]->setGameObjectTexture(newArcadeTexture);
            }
        }
    }
}

void Map::clear()
{
    for(int row = 0; row < squares.size(); row++)
    {
        for(int col = 0; col < squares[row].size(); col++)
        {
            squares[row][col]->setState(false);
        }
    }
}

Map::~Map()
{
    for(int row = 0; row < squares.size(); row++)
    {
        for(int col = 0; col < squares[row].size(); col++)
        {
            delete squares[row][col];
        }
    }
}