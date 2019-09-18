/*
	ActionType.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: An enumeration for the various types of actions a player can do
*/

#pragma once

enum  ActionType
{
	Action = 0,

	InvalidAction = 1,

	Movement = 2,

	Take = 3,

	Drop = 4,

	Save = 5,

	Look = 6,

	Inventory = 7,
	
	Quit = 8,
	
	Examine = 9

};