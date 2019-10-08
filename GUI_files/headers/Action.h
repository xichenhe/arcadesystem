// Action.h

#ifndef ACTION_H
#define ACTION_H

enum ActionType
{
	DO_NOTHING = 0,
	PAUSE,
	GAME_OVER,
	MOVE_NODES,
	MOVE_SCREENS,
	MOVE_TO_NEXT_SCREEN,
	MOVE_TO_PREVIOUS_SCREEN,
	CHANGE_MUSIC,
	CHANGE_SOUND,
	QUIT_GAME
};

struct Action
{
	ActionType actionName;
	void* actionParameter;
};
#endif