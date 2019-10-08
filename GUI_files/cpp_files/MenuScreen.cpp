 // MenuScreen.cpp

#include "MenuScreen.h"

// Override default constructor, default parameter in case none passed in
MenuScreen::MenuScreen()
{
}

// override destructor
MenuScreen::~MenuScreen() 
{
	// delete all the textures and all the buttons
	for (int i = 0; i < getArcadeTextureList()->size(); i++)
	{
		if ((*getArcadeTextureList())[i] != nullptr)
		{
			delete (*getArcadeTextureList())[i];
			(*getArcadeTextureList())[i] = nullptr;
		}
		
	}
	for (int i = 0; i < buttonList.size(); i++)
	{
		if (buttonList[i] != nullptr)
		{
			delete buttonList[i];
			buttonList[i] = nullptr;
		}
	}
}

// method to update, returns an Action struct, takes in the input as parameter
Action MenuScreen::update(SDL_Event* event)
{
		Action newAction;
		for (int i = 0; i < buttonList.size(); i++)
		{
			newAction = buttonList[i]->update(event);
			if (newAction.actionName != DO_NOTHING)
			{
				break;
			}
		}
		return newAction;
}

// method to render the current Screen
void MenuScreen::render(SDL_Renderer* renderer)
{   
	// the screen first renders all its textures
	for (int i = 0; i < getArcadeTextureList()->size(); i++)
	{
		(*getArcadeTextureList())[i]->render(renderer);
	}
	
	// the screen then renders all its buttons
	for (int i = 0; i < getButtonList()->size(); i++)
	{
		//printf("BUTTON LIST AT %i: %p \n", i, (*getButtonList())[i]);
		(*getButtonList())[i]->render(renderer);
	}
	// set the current button's selector texture destination to the current button's destination
	// we need to do this because some buttons share a selector texture so we must reposition it
}

void MenuScreen::inputText(SDL_Event* e)
{
	/*
	ArcadeTexture promptTexture;
	ArcadeTexture inputTexture;

	promptTexture.setRenderer(ren);
	inputTexture.setRenderer(ren);
	promptTexture.setFontRenderer(font);
	inputTexture.setFontRenderer(font);
	SDL_Rect dest = { 200,300,0,0 };
	SDL_Rect dest2 = { 300, 300,0,0 };

	std::string inputText = "NAME";
	inputTexture.loadFromRenderedText("C:/Users/GeffenPC/Downloads/arcade_ya/ARCADE_N.TTF", 25, inputText, { 255,0,0 });
	promptTexture.loadFromRenderedText("C:/Users/GeffenPC/Downloads/arcade_ya/ARCADE_N.TTF", 25, "ENTER TEXT:", { 255,0,0 });
	SDL_StartTextInput();
	bool quit = false;
	SDL_Event e;
	while (!quit)
	{
		dest = { 0,300,0,0 };
		dest2 = { 300, 350,0,0 };
		//The rerender text flag
		bool renderText = false;

		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			printf("\nEVENT\n");
			if (&e && (e).key.keysym.sym == SDLK_RETURN)
			{
				quit = true;
			}
			else if (&e && e.type == SDL_KEYDOWN)
			{
				//Handle backspace
				if (e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0)
				{
					//lop off character
					inputText.pop_back();
					renderText = true;
				}
			}
			else if (&e && e.type == SDL_TEXTINPUT)
			{
				//Append character
				if (inputText.length() < 6)
				{
					inputText += e.text.text;
					renderText = true;
				}

			}
		}
		if (renderText)
		{
			//Text is not empty
			if (inputText != "")
			{
				//Render new text
				inputTexture.loadFromRenderedText("C:/Users/GeffenPC/Downloads/arcade_ya/ARCADE_N.TTF", 25, inputText, { 255,0,0 });
			}
			//Text is empty
			else
			{
				//Render space texture
				inputTexture.loadFromRenderedText("C:/Users/GeffenPC/Downloads/arcade_ya/ARCADE_N.TTF", 25, " ", { 255,0,0 });
			}
		}
		inputTexture.setImageDestination(&dest2);
		promptTexture.setImageDestination(&dest);
		//SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(ren);
		promptTexture.render(ren);
		inputTexture.render(ren);
		SDL_RenderPresent(ren);
	}
	outputToFile.open("highscores.txt", ios::app);
	outputToFile << inputText << "\t" << score << endl;
	outputToFile.close();
	SDL_StopTextInput();*/
}




