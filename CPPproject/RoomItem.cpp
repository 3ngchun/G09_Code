#include <stdexcept>
#include "RoomItem.h"

char LockedDoor::printinfo() {
	char item = ']';
	return item;
}

char UnlockedDoor::printinfo() {
	char item = '[';
	return item;
}

char Chair::printinfo()
{
	char item = 'h';
	return item;
}

char Table::printinfo()
{
	char item = 'T';
	return item;
}

char Bed::printinfo()
{
	char item = '=';
	return item;
}

char Plant::printinfo()
{
	char item = '+';
	return item;
}

char Light::printinfo()
{
	char item = '*';
	return item;
}