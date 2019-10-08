#include "ArcadeTexture.h"

ArcadeTexture::ArcadeTexture()
{
	texture = nullptr;
	texRen = nullptr;
	fontRen = nullptr;

	fileWidth = 0;
	fileHeight = 0;

	isEntireSource = true;
	isEntireDestination = false;
}

// Deallocates memory
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
//Loads image at specified path
bool ArcadeTexture::loadFromFile(std::string path)
{
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

//Renders texture at given point
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






