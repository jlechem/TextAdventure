/*
	Key.cpp
	Created By:			Justin LeCheminant
	Created On:			12-24-2017
	Last Modified:		12-24-2017
	Last Modified By:	Justin LeCheminant

	Notes: Implementation of the Key class.

*/

#include "stdafx.h"

#include "Key.h"

Key::Key()
{
}

Key::Key(int id)
	: Item()
{
	_id = id;
	_canTake = true;
	_canOpen = false;
	_canAddItems = false;

}

Key::Key(int id, int itemId) 
	: Item()
{
	_id = id;
	_itemToUnlockId = itemId;
	_canTake = true;
	_canOpen = false;
	_canAddItems = false;
}

Key::~Key()
{
}