// Node.cpp

#include "Node.h"

Node::Node(SDL_Renderer* renderer_in, Node* parentNode_in)
{
	renderer = renderer_in;
	parentNode = parentNode_in;
	currentScreen = nullptr;
}

Node::~Node()
{
	printf("\n===CALLING NODE DESTRUCTOR===\n");
	// we only need to delete the screens that node holds in a vector
	for (int i = 0; i < screenList.size(); i++)
	{
		delete screenList[i];
		printf("\n===CALLING SCREEN DESTRUCTOR===\n");
	}
	for (int i = 0; i < children.size(); i++)
	{
		printf("\n===CALLING NODE CHILDREN DESTRUCTOR===\n");
		delete children[i];
	}
}

Action Node::update(SDL_Event* event)
{
	// passing the event to the current screen which returns an action
	Action newAction = currentScreen->update(event);

	// if the action is move screens then update current screen and set action to "nothing" because we handled it here
	if (newAction.actionName == MOVE_SCREENS)
	{
		currentScreen = (Screen*)newAction.actionParameter;
		newAction = { DO_NOTHING, nullptr };
	}

	// otherwise return the action to main because all other actions are executed at the main level
	return newAction;
}

void Node::render(SDL_Renderer* renderer)
{
	currentScreen->render(renderer);
}

MenuScreen* Node::createMenuScreen()
{
	MenuScreen* newMenuScreen = new MenuScreen;
	return newMenuScreen;
}

ArcadeTexture* Node::createImage(SDL_Renderer* renderer_in, std::string texturePath_in, bool isEntireDest_in)
{
	// this method initializes an arcadeTexture, the user just needs to set the position and size and add it to a screen
	ArcadeTexture* newArcadeTexture = new ArcadeTexture;
	newArcadeTexture->setRenderer(renderer_in);
	newArcadeTexture->loadFromFile(texturePath_in);
	newArcadeTexture->isEntireDestination = isEntireDest_in;
	if (isEntireDest_in == false)
	{
		newArcadeTexture->setSize(WIDTH_ORIGINAL, HEIGHT_ORIGINAL);
	}
	return newArcadeTexture;
}

SimpleButton* Node::createSimpleButton(SDL_Renderer* renderer_in, std::string texturePath_in)
{
	// this method will initialize a button and its texture, the user needs to set the position and action and add it to a screen
	SimpleButton* newSimpleButton = new SimpleButton(texturePath_in);
	newSimpleButton->setButtonTexture(createImage(renderer_in, texturePath_in));
	newSimpleButton->setButtonSize(newSimpleButton->getButtonTexture()->getWidth(), newSimpleButton->getButtonTexture()->getHeight());
	return newSimpleButton;
}

SimpleButton* Node::createSimpleButton(ArcadeTexture* arcadeTexture_in)
{
	if (arcadeTexture_in == nullptr)
	{
		printf("\nERROR: can't create button from a null arcadeTexture\n");
		return nullptr;
	}
	SimpleButton* newSimpleButton = new SimpleButton;
	newSimpleButton->setButtonTexture(arcadeTexture_in);
	newSimpleButton->setHeight(newSimpleButton->getButtonTexture()->getHeight());
	newSimpleButton->setWidth(newSimpleButton->getButtonTexture()->getWidth());
	return newSimpleButton;
}

ArcadeTexture* Node::createSimpleText(SDL_Renderer* renderer_in, std::string texturePath_in,
	int size_in, std::string text_in, int r, int g, int b )
{
	ArcadeTexture* newSimpleTexture = new ArcadeTexture();
	newSimpleTexture->setRenderer(renderer_in);
	SDL_Color textColor = { r, g, b };
	newSimpleTexture->loadFromRenderedText(texturePath_in, size_in, text_in, textColor);
	newSimpleTexture->setSize(WIDTH_ORIGINAL, HEIGHT_ORIGINAL);
	return newSimpleTexture;
}

SimpleButton* Node::createSimpleTextButton(SDL_Renderer* renderer_in, std::string texturePath_in,
	int size_in, std::string text_in, int r , int g , int b)
{
	SimpleButton* newSimpleButton = new SimpleButton(texturePath_in);
	newSimpleButton->setButtonTexture(createSimpleText(renderer_in, texturePath_in, size_in, text_in, r, g, b));
	newSimpleButton->setButtonSize(newSimpleButton->getButtonTexture()->getWidth(), newSimpleButton->getButtonTexture()->getHeight());
	return newSimpleButton;
}

OptionsButton* Node::createOptionsButton(SDL_Renderer* renderer_in,
	std::string texturePath_in, int size_in, std::string text_in, int r, int g, int b)
{
	OptionsButton* newOptionsButton = new OptionsButton( texturePath_in);
	ArcadeTexture* optionsTexture = createSimpleText(renderer_in, texturePath_in, size_in, text_in, r, g, b);
	newOptionsButton->setOptionTexture(optionsTexture);
	newOptionsButton->setHeight(newOptionsButton->getOptionTexture()->getHeight());
	newOptionsButton->setWidth(newOptionsButton->getOptionTexture()->getWidth());
	return newOptionsButton;
}

Action* Node::createAction(ActionType actionName_in, Node* actionParameter_in)
{
	Action* newAction = new Action{ actionName_in, (void*)actionParameter_in };
	return newAction;
}

Action* Node::createAction(ActionType actionName_in, int actionParameter_in)
{
	Action* newAction = new Action{ actionName_in, (void*)actionParameter_in };
	return newAction;
}

Action* Node::createAction(ActionType actionName_in, Screen* actionParameter_in)
{
	Action* newAction = new Action{ actionName_in, (void*)actionParameter_in };
	return newAction;
}

Action* Node::createAction(ActionType actionName_in, Mix_Music* actionParameter_in)
{
	Action* newAction = new Action{ actionName_in, (void*)actionParameter_in };
	return newAction;
}
