// Action.h

// DESCRIPTION
// An "Action" is the effect of events within the Arcade
// System and is a simple alternative for something like a
// callback. An Action has an "ActionType", which tells you
// what the action does or is and an "ActionParameter" which
// holds the "data" for the action.

// EXAMPLE
// The most common use for an Action is to give a Button
// functionality (Every button object has an Action field
// so that it can do something when it is clicked).
// A button that takes you from the Main Menu to another
// point in the Arcade would have MOVE_SCREENS or MOVE_NODES
// as the ActionType depending on the context, and a pointer to a
// Screen or Node object that the button takes you to

#ifndef ACTION_H
#define ACTION_H

// As seen below, Actions are generic as they are a alternative
// to callback functions which are more complex. This limits the control and
// customizability of the the Arcade System but also makes it predictable which
// makes it less susceptible to undefined behavior caused by user defined callbacks 
// More action types may be added but must be handled accordingly 
enum ActionType
{
	DO_NOTHING = 0,
	PAUSE,
	GAME_OVER,
	MOVE_NODES,
	MOVE_SCREENS,
	CHANGE_MUSIC,
	CHANGE_SOUND,
	QUIT_GAME
};

// Note how the actionParameter is a void pointer.
// This allows any type of paramter to be stored
// (screen pointer, node pointer, music pointer, ...)
// which makes it flexible to different action types.
// Also, something like a button that holds an action
// should not be aware of the data that action holds.
// For example, a button should not be aware of a "Screen"
// type so making the pointer void prevents that
struct Action
{
	ActionType actionName;
	void* actionParameter;
};
#endif