// TetrisGame.cpp
	#include "TetrisGame.h"

	void TetrisGame::addPiece(std::string path, point tlc, std::vector<std::vector<int> > piece)
	{
		for(int row = 0; row < piece.size(); row++)
		{
			for(int col = 0; col < piece[row].size(); col++)
			{
				if(piece[row][col] == 1)
				{
					ArcadeTexture* newArcadeTexture = new ArcadeTexture;
					newArcadeTexture->setRenderer(m->getRenderer());
					newArcadeTexture->loadFromFile(path);
					newArcadeTexture->isEntireDestination = false;
					newArcadeTexture->setSize(m->getTiles()[row][col]->getWidth(),
					m->getTiles()[row][col]->getHeight());
					newArcadeTexture->setPosition(m->getSideSize()*(tlc.x+col),
					m->getSideSize()*(tlc.y+row));
					Tile* newPiece = new Tile;
					newPiece->setGameObjectTexture(newArcadeTexture);
					newPiece->setState(true);
					addEntity(newPiece);
					addMovingEntity(newPiece);
				}
			}
		}
	}
	
	void TetrisGame::setMap(Map* m_in)
	{
		m = m_in;
		for(int row = 0; row < (m->getTiles()).size(); row++)
		{
			for(int col = 0; col < (m->getTiles())[row].size(); col++)
			{
				addEntity((m->getTiles())[row][col]);
			}
		}
	}
	
	Action TetrisGame::update(SDL_Event* event)
	{
		if(getIsNewGame())
		{
			newGame();
		}
	
		Action newAction = {DO_NOTHING, nullptr};
	
		if(event)
		{
			if((*event).type == SDL_KEYDOWN && (*event).key.keysym.sym == SDLK_DOWN)
			{
				moveDown(getMovingEntities());
                rot.y+=m->getSideSize();
			}
			else if((*event).type == SDL_KEYDOWN && (*event).key.keysym.sym == SDLK_UP)
			{   
                rotatePiece(getMovingEntities(),{30,30});
				moveUp(getMovingEntities());
                if(!getNextPiece)
                {
                    count=59;
                }
			}
			else if((*event).type == SDL_KEYDOWN && (*event).key.keysym.sym == SDLK_LEFT)
			{
				moveLeft(getMovingEntities());
                rot.x-=m->getSideSize();

			}
			else if((*event).type == SDL_KEYDOWN && (*event).key.keysym.sym == SDLK_RIGHT)
			{
				moveRight(getMovingEntities());

			}
		}
        count++;
        if(count==60)
        {
            for (int i=0; i<getMovingEntities().size();i++)
            {
                int x=getMovingEntities()[i]->getXPos();
                int y=getMovingEntities()[i]->getYPos();

                int nextRow=(getMovingEntities()[i]->getHeight()+y)/(m->getSideSize());
                int nextCol=x/(m->getSideSize());

                if(nextRow==m->getxDim() || (m->getTiles()[nextRow][nextCol])->getState()==true)
                {
                    getNextPiece=true;
                }
            }
            if(!getNextPiece)
            {
                moveDown(getMovingEntities());
                rot.y+=m->getSideSize();
            }
            else
            {
                for(int i=0; i<getMovingEntities().size();i++)
                {
                    int x=getMovingEntities()[i]->getXPos();
                    int y=getMovingEntities()[i]->getYPos();
                    int nextrow=getMovingEntities()[i]->getHeight()+y/(m->getSideSize());
                    int nextCol=(x/(m->getSideSize()));

                    m->getTiles()[y/(m->getSideSize())][x/(m->getSideSize())]=(Tile*)(getMovingEntities()[i]);
                    m->getTiles()[y/(m->getSideSize())][x/(m->getSideSize())]->setState(true);
                }
                count=0;
                return newAction;
            }
            count=0;
        }
		logic();
		return newAction;
	}
	
	void TetrisGame::newGame()
	{
		addPiece("brickBreakerNodeImages/yellowBrickTexture.png", {0,0}, pieces.at(0));
		setisNewGame(false);
	}
	
	void TetrisGame::logic()
    {
        if(pieceIndex==pieces.size())
        {
            pieceIndex=0;

        }
        point p1={0,0};
        switch(pieceIndex)
        {
            case(0):
            {
                addPiece("brickBreakerNodeImages/yellowBrickTexture.png",p1,pieces.at(pieceIndex));
                break;
            }
            case(1):
            {
                addPiece("brickBreakerNodeImages/blueBrickTexture.png",p1,pieces.at(pieceIndex));
                break;
            }
            case(2):
            {
                addPiece("brickBreakerNodeImages/redBrickTexture.png",p1,pieces.at(pieceIndex));
                break;
            }
            case(3):
            {
                addPiece("brickBreakerNodeImages/redBrickTexture.png",p1,pieces.at(pieceIndex));
                break;
            }
        }
    }
	
	bool TetrisGame::moveLeft(std::vector<Entity*>& piece)
	{
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			int x = getMovingEntities()[i]->getXPos();
			int y = getMovingEntities()[i]->getYPos();
	
			int nextCol = (x-getMovingEntities()[i]->getWidth())/(m->getSideSize());
			int nextRow = y/(m->getSideSize());
			if(nextCol < 0)
			{
				return false;
			}
		}
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			getMovingEntities()[i]->setXPos(getMovingEntities()[i]->getXPos() - getMovingEntities()[i]->getWidth());
		}
	}
	
	bool TetrisGame::moveRight(std::vector<Entity*>& piece)
	{
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			int x = getMovingEntities()[i]->getXPos();
			int y = getMovingEntities()[i]->getYPos();
	
			int nextCol = (x+getMovingEntities()[i]->getWidth())/(m->getSideSize());
			int nextRow = y/(m->getSideSize());
			if(nextCol == m->getxDim())
			{
				return false;
			}
		}
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			getMovingEntities()[i]->setXPos(getMovingEntities()[i]->getXPos() + getMovingEntities()[i]->getWidth());
		}
	}
	
	bool TetrisGame::moveDown(std::vector<Entity*>& piece)
	{
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			int x = getMovingEntities()[i]->getXPos();
			int y = getMovingEntities()[i]->getYPos();
	
			int nextCol = (x/m->getSideSize());
			int nextRow = (y+getMovingEntities()[i]->getHeight())/(m->getSideSize());
			if(nextRow == m->getyDim())
			{
				return false;
			}
		}
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			getMovingEntities()[i]->setYPos(getMovingEntities()[i]->getYPos() + getMovingEntities()[i]->getHeight());
		}
	}
	
	bool TetrisGame::moveUp(std::vector<Entity*>& piece)
	{
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			int x = getMovingEntities()[i]->getXPos();
			int y = getMovingEntities()[i]->getYPos();
	
			int nextCol = (x/m->getSideSize());
			int nextRow = (y-getMovingEntities()[i]->getHeight())/(m->getSideSize());
			if(nextRow < 0)
			{
				return false;
			}
		}
		for(int i = 0; i < getMovingEntities().size(); i++)
		{
			getMovingEntities()[i]->setYPos(getMovingEntities()[i]->getYPos() - getMovingEntities()[i]->getHeight());
		}
	}
	
    void TetrisGame::rotatePiece(std::vector<Entity* > & piece_in ,point rot_in)
    {
        int x=piece_in[0]->getXPos();
        int y=piece_in[0]->getYPos();

        int a=x+rot_in.x;
        int b=y+rot_in.y;

        if(!hasRotated)
        {
            rot={a,b};
        }
        else
        {
            a=rot.x;
            b=rot.y;

        }
        
        for(int i=0; i<piece_in.size();i++)//iterating throught each Tile
        {
            x=piece_in[i]->getXPos();
            y=piece_in[i]->getYPos();

            int newX=(y-b)+a;//set the new x and y point
            int newY=-(x-a)+b-30;

            if(newX>0 && newY>0 && newX<(m->getxDim())*(m->getSideSize()) && newY<(m->getyDim())*(m->getSideSize()))
            {   // not valid rotation 
                if(m->getTiles()[newY/(m->getSideSize())][newX/(m->getSideSize())]->getState()==true)//two dimensional vector
                {
                    return;
                }
            }

            for(int i=0; i<piece_in.size();i++)
            {
                x=piece_in[i]->getXPos();
                y=piece_in[i]->getYPos();

                int newX=(y-b)+a;//set the new x and y point
                int newY=-(x-a)+b-30;

                piece_in[i]->setXPos(newX);
                piece_in[i]->setYPos(newY);

            }

            for( int i=0; i<piece_in.size();i++)
            {
                x=piece_in[i]->getXPos();
                y=piece_in[i]->getYPos();

                while(x<0)
                {
                    x+=m->getSideSize();
                    moveRight(getMovingEntities());
                }
                while(x>(m->getxDim()-1)*(m->getSideSize()))
                {
                    x-=m->getSideSize();
                    moveRight(getMovingEntities());
                }
                while(y>(m->getyDim()-1)*(m->getSideSize()))
                {
                    y-=m->getSideSize();
                    moveUp(getMovingEntities());
                }
            }
        }
    }