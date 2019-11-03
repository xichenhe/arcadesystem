#include "Node.h"
#include "Config.h"
#include "SimpleGame.h" 
#include <stdio.h>
#include "Paddle.h"
class GameNode : public Node // publicly inherits from Node
{
public:
    // Constructor                                            // initializer list
    GameNode(SDL_Renderer* renderer_in, Node* parentNode_in): Node(renderer_in, parentNode_in)
    {
        // create a gameScreen and add a texture to it
        SimpleGame* game = new SimpleGame; 
        game->addTextureToScreen(createImage(renderer_in,"brickBreakerNodeImages/brickBreakerScreen.png", true));
        
        // create an entity for the gameScreen
        Ball* ball = new Ball;

        // create an image for the entity
        ArcadeTexture* ballTexture = createImage(renderer_in, "brickBreakerNodeImages/ballTexture.png");
        ball->setGameObjectTexture(ballTexture);
        ball->setState(true);

        Paddle* paddle =new Paddle;
        ArcadeTexture* paddleTexture=createImage(renderer_in,"brickBreakerNodeImages/paddleTexture.png");
        paddle->setGameObjectTexture(paddleTexture);
        paddle->setState(true);


        game->addEntity(ball); 
        game->addMovingEntity(ball);
        game->setBall(ball);

        game->addEntity(paddle); 
        game->addMovingEntity(paddle);
        game->setPaddle(paddle);



        game->setisNewGame(true);
        game->setGameState(true);

        MenuScreen* gameOverScreen=createMenuScreen();
        gameOverScreen->addTextureToScreen(createImage(renderer_in,"brickBreakerNodeImages/pauseScreenBackgroundTexture"));

        ArcadeTexture* gameOverText=createSimpleText(renderer_in,"fonts/retro/italic.ttf",100,"GAME OVER",255,2);
        gameOverText->setPosition(windowWidth/2-gameOverText->getW()/2,25);
        gameOverScreen->addTextureToScreen(gameOverText);

        SimpleButton* newGameButton=createSimpleTextButton(renderer_in,"fonts/retro/italic.ttf",30,"NEW GAME",255);
        newGameButton->setButtonPosition(windowWidth/2-newGameButton->getWidth()/2,278);
        newGameButton->set



        this->addScreen(game);
        this->setCurrentScreen(game);
    }
};