// ArcadeTexture.h

// This is a utility of the virtual arcade system to help render and handle images and text
// In general, the ArcadeTexture object is a way to interact with and initialize textures
// The main purpose of the ArcadeTexture class is to make rendering easier and more organized


#ifndef ARCADETEXTURE_H
#define ARCADETEXTURE_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Config.h"
#include <string>

class ArcadeTexture
{
public:
	ArcadeTexture();

	//Deallocates memory
	~ArcadeTexture();
	
	// ACCESSORS
	SDL_Rect getImageDestination()
	{
		return imageDestination;
	}

	TTF_Font* getFontRenderer()
	{ 
		return fontRen; 
	}

	SDL_Texture* getSDLTexture()
	{
		return texture;
	}

	// MUTATORS
	void setRenderer(SDL_Renderer* renderer_in)
	{
		if (renderer_in == nullptr)
		{
			printf("WARNING! Setting ArcadeTexture texture renderer to a nullptr.");
		}
		texRen = renderer_in;
	}

	int getX() { return imageDestination.x; }
	int getY() { return imageDestination.y; }
	int getW() { return imageDestination.w; }
	int getH() { return imageDestination.h; }

	void setXPosition(int x_in)
	{
		imageDestination.x = x_in;
	}

	void setYPosition(int y_in)
	{
		imageDestination.y = y_in;
	}

	void setPosition(int x_in, int y_in)
	{
		if (x_in == CENTER_X)
		{
			x_in = windowWidth / 2 - fileWidth / 2;
		}
		if (x_in == CENTER_Y)
		{
			x_in = windowHeight / 2 - fileHeight / 2;
		}
		imageDestination.x = x_in;
		imageDestination.y = y_in;
	}

	void setSize(int w_in, int h_in)
	{
		if (w_in == WIDTH_ORIGINAL)
		{
			w_in = fileWidth;
		}
		if (h_in == HEIGHT_ORIGINAL)
		{
			h_in = fileHeight;
		}
		imageDestination.w = w_in;
		imageDestination.h = h_in;
	}

	// this method helps set the source of the SDL_texture by creating a rectangle
	/*void setTextureClip(int x_in, int y_in, int w_in, int h_in)
	{
		// if all the values are negative that means set the clip to a nullptr
		// this will set the source raectangle to the entire image in the SDL_RenderCopy method
		if (w_in < 0 && h_in < 0 && x_in < 0 && y_in < 0)
		{
			isEntireSource = true;
			return;
		}

		if (w_in == WIDTH_ORIGINAL)
		{
			w_in = fileWidth;
		}

		if (h_in == HEIGHT_ORIGINAL)
		{
			h_in = fileHeight;
		}

		// center in the middle width of the window
		if (x_in == CENTER_X)
		{
			x_in = windowWidth/2 - fileWidth / 2;
		}

		// center in middle height of the window
		if (y_in == CENTER_Y)
		{
			y_in = windowHeight/2 - fileHeight / 2;
		}

		textureClip = { x_in, y_in, w_in, h_in };
	}*/

	// this method helps set the destination of the SDL_texture by creating a rectangle
	/*void setImageDestination(int x_in, int y_in, int w_in, int h_in)
	{

		// if they are all negative, meaning no parameter was passed in to the original function then it means take up the entire screen
		// by making the imageDestination nullptr
		if (w_in < 0 && h_in < 0 && x_in < 0 && y_in < 0)
		{
			isEntireDestination = true;
			return;
		}

		if (w_in == WIDTH_ORIGINAL)
		{
			w_in = fileWidth;
		}
		if (h_in == HEIGHT_ORIGINAL)
		{
			h_in = fileHeight;
		}

		// center in the middle width of the window
		if (x_in == CENTER_X)
		{
			x_in = windowWidth / 2 -w_in / 2;
		}

		if (x_in == LEFT)
		{
			x_in = 50;
		}

		if (x_in == RIGHT)
		{
			x_in = windowWidth - 50 - w_in;
		}

		// center in middle height of the window
		if (y_in == CENTER_Y)
		{
			y_in = windowHeight / 2 - h_in / 2;
		}

		if (y_in == TOP)
		{
			y_in = 20;
		}

		if (y_in == BOTTOM)
		{
			y_in = windowHeight - 50;
		}

		imageDestination = { x_in, y_in, w_in, h_in };
	}*/

	// this method is used to create image textures that can be rendered
	bool loadFromFile(std::string path);

	// this method is used to create text textures that can be rendered
	bool loadFromRenderedText(std::string filePath, int size, std::string textureText, SDL_Color textColor);

	// this method is used to edit a texture to make it look selected
	void setSelected(bool selected_in);

	// this is used to deallocate an ArcadeTexture object by freeing the SDL texture
	void myFree();

	// this method renders an ArcadeTexture to the screen using the underlying SDL texture
	void render(SDL_Renderer* renderer);

	bool isEntireSource;
	bool isEntireDestination;
private:
	//The actual hardware texture
	SDL_Texture* texture ;

	//Renderer
	SDL_Renderer* texRen;

	// the font object
	TTF_Font* fontRen;

	// image rectangle destination
	SDL_Rect imageDestination;

	// rectangle crop
	SDL_Rect textureClip;

	// original image dimensions
	int fileWidth;
	int fileHeight;
};

#endif

