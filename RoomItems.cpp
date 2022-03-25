#include <iostream>
using namespace std;

class RoomItems
{
public:
	void display(string item)
	{
		cout << item;
	}
};

class LockedDoor : public RoomItems
{
public:
	void display(string item)
	{
		//item = "]";
		RoomItems::display(item);
	}
};

class UnlockedDoor : public RoomItems
{
public:
	void display(string item)
	{
		//item = "[";
		RoomItems::display(item);
	}
};

class Chair : public RoomItems
{
public:
	void display(string item)
	{
		//item = "h";
		RoomItems::display(item);
	}
};

class Table : public RoomItems
{
public:
	void display(string item)
	{
		//item = "T";
		RoomItems::display(item);
	}
};

class Bed : public RoomItems
{
public:
	void display(string item)
	{
		//item = "=";
		RoomItems::display(item);
	}
};

class Plant : public RoomItems
{
public:
	void display(string item)
	{
		//item = "+";
		RoomItems::display(item);
	}
};

class Light : public RoomItems
{
public:
	void display(string item)
	{
		//item = "*";
		RoomItems::display(item);
	}
};

int main()
{
	LockedDoor ld;
	ld.display("]");

	UnlockedDoor ud;
	ud.display("[");

	Chair c;
	c.display("h");

	Bed b;
	b.display("=");

	Light l;
	l.display("*");

	Plant p;
	p.display("+");

	Table t;
	t.display("T");
}