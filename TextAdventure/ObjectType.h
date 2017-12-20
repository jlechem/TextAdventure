/*
	ObjectType.h
	Created By:		Justin LeCheminant
	Created On:		12-18-2017
	Last Modified:	12-18-2017
	Notes: An enumeration for the various types of objects in the game, Item, Room, Treasure, Player, etc
*/

#pragma once

#include "stdafx.h"

/// <summary>
/// An enumeration that states the type of object we have in the game
/// </summary>
enum ObjectType
{
	/// <summary>
	/// The player
	/// </summary>
	PlayerObject,

	/// <summary>
	/// The item
	/// </summary>
	ItemObject,

	/// <summary>
	/// The treasure
	/// </summary>
	TreasureObject,

	/// <summary>
	/// The room
	/// </summary>
	RoomObject

};