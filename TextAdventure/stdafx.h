/*
	StdAfx.h
	Created By:			Justin LeCheminant
	Created On:			12-18-2017
	Last Modified:		12-19-2017
	Last Modified By:	Justin LeCheminant

	Include file for standard system include files,
	or project specific include files that are used frequently, but
	are changed infrequently

*/

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO: reference additional headers your program requires here
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <locale>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "Directions.h"

using namespace std;

#define NORTH "north"
#define SOUTH "south"
#define EAST "east"
#define WEST "west"
#define NORTHEAST "northeast"
#define NORTHWEST "northwest"
#define SOUTHEAST "southeast"
#define SOUTHWEST "southwest"

#define NORTH_SHORT "n"
#define SOUTH_SHORT "s"
#define EAST_SHORT "e"
#define WEST_SHORT "w"
#define NORTHEAST_SHORT "ne"
#define NORTHWEST_SHORT "nw"
#define SOUTHEAST_SHORT "se"
#define SOUTHWEST_SHORT "sw"

#define NORTHEAST_SPACE "north east"
#define NORTHWEST_SPACE "north west"
#define SOUTHEAST_SPACE "south east"
#define SOUTHWEST_SPACE "south west"

#define UP "up"
#define UP_SHORT "u"
#define DOWN "down"
#define DOWN_SHORT "d"