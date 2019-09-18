/*
	ObjectType.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	01-02-2018
	Notes: An enumeration for the various types of objects in the game, Item, Room, Treasure, Player, etc
*/

#pragma once

#include "stdafx.h"

/// <summary>
/// An enumeration that states the type of object we have in the game
/// </summary>
enum ObjectType
{
	PlayerObject = 0,
	
	NPC = 1,

	Enemy = 2,

	ItemObject = 3,

	TreasureObject = 4,

	RoomObject = 5,

	KeyObject = 6,

	DoorObject = 7,

	WeaponObject = 8,

	ArmorObject = 9

};