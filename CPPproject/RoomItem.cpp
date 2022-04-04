#include <stdexcept>
#include "RoomItem.h"

char RoomItems::printinfo() {
	return 0;
}
string RoomItems::getItemName() {
	return " ";
}

char LockedDoor::printinfo() {
	char item = ']';
	return item;
}
string LockedDoor::getItemName() {
	return itemName;
}

char UnlockedDoor::printinfo() {
	char item = '[';
	return item;
}
string UnlockedDoor::getItemName() {
	return itemName;
}

char Chair::printinfo()
{
	char item = 'h';
	return item;
}
string Chair::getItemName() {
	return itemName;
}

char Table::printinfo()
{
	char item = 'T';
	return item;
}
string Table::getItemName() {
	return itemName;
}

char Bed::printinfo()
{
	char item = '=';
	return item;
}
string Bed::getItemName() {
	return itemName;
}

char Plant::printinfo()
{
	char item = '+';
	return item;
}
string Plant::getItemName() {
	return itemName;
}

char Light::printinfo()
{
	char item = '*';
	return item;
}
string Light::getItemName() {
	return itemName;
}