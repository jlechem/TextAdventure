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
	: ObjectBase()
{
}

Key::Key(int id)
	: ObjectBase()
{
	_id = id;
}

Key::Key(int id, int itemId) 
	: ObjectBase()
{
	_id = id;
	_itemToUnlockId = itemId;
}

Key::~Key()
{
}