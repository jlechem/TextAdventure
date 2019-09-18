/*
	WinTypes.h
	Created By:		Justin LeCheminant
	Created On:		9-18-2019
	Last Modified:	9-18-2019
	Notes: An enumeration for the various things that can trigger a win of the game. This might be better served as a class or something
	else but this is a rough start.
*/

#pragma once

enum WinTypes
{
	Unknown = 0,

	Score = 1,

	Boss = 2,

	Item = 3,

	Room = 4
};