/*
	Rooms.h
	Created By:		Justin LeCheminant
	Created On:		12-29-2017
	Last Modified:	12-29-2017

	Notes: A class used to hold a singleton to ALL the rooms in the game

*/

#pragma once

#include "stdafx.h"

#include "Room.h"

class Rooms
{
public:
	Rooms(Rooms const&) = delete;
	void operator=(Rooms const&) = delete;
	~Rooms();
	
	static Rooms& getInstance();
	vector<Room*>& getRooms();

private:
	Rooms();
	vector<Room*> s_rooms;

};