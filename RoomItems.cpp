#include <iostream>

using namespace std;

class RoomItems
{
public:
	char printinfo(char item) {}
};

class LockedDoor : public RoomItems
{
public:
	char printinfo(char item)
	{
		item = ']';
		return item;
	}
};

class UnlockedDoor : public RoomItems
{
public:
	char printinfo(char item)
	{
		item = '[';
		return item;
	}
};

class Chair : public RoomItems
{
public:
	char printinfo(char item)
	{
		item = 'h';
		return item;
	}
};

class Table : public RoomItems
{
public:
	char printinfo(char item)
	{
		item = 'T';
		return item;
	}
};

class Bed : public RoomItems
{
public:
	char printinfo(char item)
	{
		item = '=';
		return item;
	}
};

class Plant : public RoomItems
{
public:
	char printinfo(char item)
	{
		item = '+';
		return item;
	}
};

class Light : public RoomItems
{
public:
	char printinfo(char item)
	{
		item = '*';
		return item;
	}
};