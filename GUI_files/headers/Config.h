// Config.h

// DESCRIPTION
// This is a config file for some global constants

#ifndef CONFIG_H
#define CONFIG_H

const int windowHeight = 480;
const int windowWidth = 300;

enum geometryPosition
{
	CENTER_X = 10000,
	CENTER_Y,
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
	WIDTH_ORIGINAL,
	HEIGHT_ORIGINAL
};

struct point
{
    int x;
	int y;
};

#endif
