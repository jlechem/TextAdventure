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
	Action,
	InvalidAction,
	Movement,
	Take,
	Drop,
	Save,
	Look,
	Inventory,
	Quit,
	Examine
};