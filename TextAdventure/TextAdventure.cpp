// TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Room.h"
#include "Player.h"
#include "Helpers.h"

using namespace std;

string timeConversion(string s) {
	
	string result;

	char* buffer;

	s.copy(buffer, 8, 0);

	// get the AM || PM
	bool twelvish = s[8] == 'A';

	// convert PM to digits
	if (!twelvish)
	{
		
	}

	result = buffer;

	return result;

}

int main()
{
	string s;
	cin >> s;
	string result = timeConversion(s);
	cout << result << endl;
	return 0;

	// declare some variables we need to use
	
	// a few global search values
	//unique_ptr<vector<shared_ptr<Room>>> rooms;
	//unique_ptr<vector<unique_ptr<Item>>> items;
	//unique_ptr<vector<unique_ptr<Treasure>>> treasures;
	//unique_ptr<vector<string>> verbs;

	//// the player
	//unique_ptr<Player> player = make_unique<Player>();

	//// load our data
	//LoadVerbs(std::move(verbs));
	//LoadItems(std::move(items));
	//LoadTreasures(std::move(treasures));
	//LoadRooms(std::move(rooms));
	//LoadPlayer(std::move(player));

	//// TODO: Show an intro??

	//// run the game loop
	//while (!GaveOver(std::move(player)))
	//{

	//}

 //   return 0;

}
