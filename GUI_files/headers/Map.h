// Map.h

#ifndef MAP_H
#define MAP_H

#include "Entity.h"
#include "Config.h"
#include "Tile.h"
#include <vector>
#include <string>

class Map
{
    public:
    // constructor
    Map(int sideSize_in, int xDim_in, int yDim_in, SDL_Renderer* ren_in);

    // Destructor
    ~Map();
    
    // used initialize tiles on the map
    void config(std::string path, point tlc, std::vector<std::vector<int> > squares_in, bool canMove);
    
    // accessors
    int getxDim() {return xDim;}
    int getyDim() {return yDim;}
    int getSideSize(){return sideSize;}
    SDL_Renderer* getRenderer() {return ren;}
    std::vector<std::vector<Tile*> >& getTiles() {return squares;}

    void clear();

    private:
    int xDim;
    int yDim;
    int sideSize;
    SDL_Renderer* ren;
    std::vector<std::vector<Tile*> > squares;
};

#endif