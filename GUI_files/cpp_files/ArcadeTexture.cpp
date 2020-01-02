// ArcadeTexture.cpp

#include "ArcadeTexture.h"

// Default Constructor
ArcadeTexture::ArcadeTexture()
{
	texture = nullptr;
	texRen = nullptr;
	fontRen = nullptr;

	fileWidth = 0;
	fileHeight = 0;

	// no cropping by defualt
	isEntireSource = true;
	isEntireDestination = false;
}

// MUTATORS
void ArcadeTexture::setXSrc(int x_in)
{
	if(x_in < 0)
	{
		printf("WARNING: x position of texture (%i) is negative", x_in);
	}
	imageDestination.x = x_in;
}

void ArcadeTexture::setYSrc(int y_in)
{
	if(y_in < 0)
	{
		printf("WARNING: y position of texture (%i) is negative", y_in);
	}
	imageDestination.y = y_in;
}

void ArcadeTexture::setPositionSrc(int x_in, int y_in)
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

void ArcadeTexture::setSizeSrc(int w_in, int h_in)
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

void ArcadeTexture::setX(int x_in)
{
	if(x_in < 0)
	{
		printf("WARNING: x position of texture (%i) is negative", x_in);
	}
	imageDestination.x = x_in;
}

void ArcadeTexture::setY(int y_in)
{
	if(y_in < 0)
	{
		printf("WARNING: y position of texture (%i) is negative", y_in);
	}
	imageDestination.y = y_in;
}

void ArcadeTexture::setPosition(int x_in, int y_in)
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

void ArcadeTexture::setSize(int w_in, int h_in)
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

// Destructor
ArcadeTexture::~ArcadeTexture() 
{ 
	myFree(); 
}

void ArcadeTexture::myFree()
{
	// Free texture if it exists
	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
		texture = nullptr;
		fileWidth = 0;
		fileHeight = 0;
	}
	if (fontRen != nullptr)
	{
		TTF_CloseFont(fontRen);
	}
}
// Creates texture from image at specified path
bool ArcadeTexture::loadFromFile(std::string path)
{
	// if want to reload a texture, clear it first
	SDL_DestroyTexture(texture);
	texture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		// Create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(texRen, loadedSurface);

		if (texture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			fileWidth = loadedSurface->w;
			fileHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return texture != nullptr;
}

// used to create text
bool ArcadeTexture::loadFromRenderedText(std::string filePath, int size, std::string textureText, SDL_Color textColor)
{
	SDL_DestroyTexture(texture);
	texture = nullptr;
	TTF_CloseFont(fontRen);
	fontRen = TTF_OpenFont(filePath.c_str(), size);
	if (fontRen == nullptr)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	else
	{
		//Render text surface
		SDL_Surface* textSurface = TTF_RenderText_Solid(fontRen, textureText.c_str(), textColor);
		if (textSurface == nullptr)
		{
			printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		}
		else
		{
			//Create texture from surface pixels
			texture = SDL_CreateTextureFromSurface(texRen, textSurface);
			if (texture == nullptr)
			{
				printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get image dimensions
				fileWidth = textSurface->w;
				fileHeight = textSurface->h;
			}

			//Get rid of old surface
			SDL_FreeSurface(textSurface);
		}
	}
	//Return success
	return texture != nullptr;
}

void ArcadeTexture::setSelected(bool selected_in)
{
	//Blend texture
	if (selected_in)
	{
		SDL_SetTextureAlphaMod(texture, 100);
	}
	else
	{
		SDL_SetTextureAlphaMod(texture, 255);
	}
	
}

// Renders texture at given point
void ArcadeTexture::render(SDL_Renderer* renderer)
{
	SDL_Rect* source = &textureClip;
	SDL_Rect* dest = &imageDestination;

	if (isEntireSource)
	{
		source = nullptr;
	}
	if (isEntireDestination)
	{
		dest = nullptr;
	}
	SDL_RenderCopy(renderer, texture, source, dest);
}