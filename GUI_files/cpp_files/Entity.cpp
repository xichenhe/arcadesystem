// Entity.cpp

#include "Entity.h"

void Entity::setGameObjectTexture(ArcadeTexture* gameObjectTexture_in) 
{ 
    if(gameObjectTexture_in != nullptr)
    {
        gameObjectTexture = gameObjectTexture_in;
        xPos = gameObjectTexture->getX();
        yPos = gameObjectTexture->getY();
        width = gameObjectTexture->getWidth();
        height = gameObjectTexture->getHeight();
    }
}

void Entity::setXPos(int xPos_in) 
{ 
    xPos = xPos_in;
    if(gameObjectTexture)
    {
        gameObjectTexture->setX(xPos);
    } 
}

void Entity::setYPos(int yPos_in) 
{
    yPos = yPos_in;
    if(gameObjectTexture)
    {
        gameObjectTexture->setY(yPos);
    } 
}

void Entity::render(SDL_Renderer* renderer)
{
    if(getGameObjectTexture() == nullptr)
    {
        printf("\n null texture, cannot render \n");
    }
    gameObjectTexture->render(renderer); 
}
