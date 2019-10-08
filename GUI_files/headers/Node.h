// Node.h

// This is the base class of “the top level” (Node -> Screen -> Button) and first object created from the main loop
// Abstractly, the Node object represents a collection of screens and is a discrete point in the menu system. 
// The main purpose of the Node is to provide some organization and structure.

// Note: Even though this class isn't abstract it shouldn't be instantiated. Instead, inherit from itto create other nodes.

#ifndef NODE_H
#define NODE_H

#include "Config.h"
#include "SimpleButton.h"
#include "OptionsButton.h"
#include "Screen.h"
#include "MenuScreen.h"
#include "Action.h"
#include "SDL_mixer.h"
#include <vector>

class Node
{
public:
	// CONSTRUCTOR: every node must have a renderer that it passes to screens and buttons for creating arcade textures
	// Also, every node gets its parent passed to it when created, almost always just use 'this'. 
	Node(SDL_Renderer* renderer_in = nullptr, Node* parentNode_in = nullptr);

	// DESTRUCTOR: nodes are in charge of calling destrutors of screens and child nodes. It is virtual in case
	// a specific node allocates extra resources that need to be cleared such as music objects.
	virtual ~Node();


	// ACCESSORS
	std::vector<Screen*>* getScreenList() { return &screenList; }

	SDL_Renderer* getRenderer() { return renderer; }
	
	Node* getParentNode() { return parentNode; }

	Screen* getCurrentScreen() { return currentScreen; }

	//int getCurrentScreenIndex() { return currentScreenIndex; }

	// don't need access to children vector outside member functions


	// MUTATORS: only need to change these member variables
	void setCurrentScreen(Screen* currentScreen_in) { currentScreen = currentScreen_in; }

	void addScreen(Screen* screen_in){ screenList.push_back(screen_in); }


	// GENERAL NODE METHODS
	// Nodes have enter and exit functions that can be implemented if needed. For example, if member variables need
	// to be reset or initialized upon entering and exiting a node.
	virtual void enter() {}
	virtual void exitNode() {}

	// method to update, returns an Action struct, takes in the event (keystroke, mouse click, etc) as parameter
	Action update(SDL_Event* event);

	// method to render the current Node, passes in the renderer to render textures to the screen
	void render(SDL_Renderer* renderer);


	// HELPER METHODS: these are used to automate the creation process of actions, buttons, screens, textures, etc
	ArcadeTexture* createImage(SDL_Renderer* renderer_in, std::string texturePath_in, bool isEntireDest_in = false);

	ArcadeTexture* createSimpleText(SDL_Renderer* renderer_in, std::string texturePath_in,
		int size_in, std::string text_in, int r = 255, int g = 0, int b = 0);

	SimpleButton* createSimpleTextButton(SDL_Renderer* renderer_in, std::string texturePath_in,
		int size_in, std::string text_in, int r = 255, int g = 0, int b = 0);

	SimpleButton* createSimpleButton(ArcadeTexture* arcadeTexture_in);
	SimpleButton* createSimpleButton(SDL_Renderer* renderer_in, std::string texturePath_in);

	OptionsButton* createOptionsButton(SDL_Renderer* renderer_in,
		std::string texturePath_in, int size_in, std::string text_in, int r, int g, int b);

	MenuScreen* createMenuScreen();

	Action* createAction(ActionType actionName_in, Node* actionParameter_in);
	Action* createAction(ActionType actionName_in, int actionParameter_in);
	Action* createAction(ActionType actionName_in, Screen* actionParameter_in);
	Action* createAction(ActionType actionName_in, Mix_Music* actionParameter_in);

	// has a vector of all children, used in constructor and destructor
	std::vector<Node*> children;
private:
	// has a renderer to pass to all nodes
	SDL_Renderer* renderer;

	// has a pointer to the parent Node
	Node* parentNode;

	// has a pointer to the current screen
	Screen* currentScreen;

	// has a vector of screen pointers
	std::vector<Screen*> screenList;
};

#endif