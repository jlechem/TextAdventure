/*
	Key.h
	Created By:			Justin LeCheminant
	Created On:			12-24-2017
	Last Modified:		12-24-2017
	Last Modified By:	Justin LeCheminant

	Notes: Class that represents a key that opens a door or item

*/

#pragma once

#include "Item.h"

class Key :
	public Item
{
public:
	Key();
	Key(int);
	Key(int, int);
	~Key();

private:
	int _id;
	int _itemToUnlockId;

};