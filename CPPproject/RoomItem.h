#pragma once
#ifndef ROOMITEM_H
#define ROOMITEM_H

#include <iostream>

using namespace std;

class RoomItems
{
private:
	string itemName;
	int x = 0;
	int y = 0;
public:
	string getItemName();
	char printinfo();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

class LockedDoor : public RoomItems
{
private:
	int x = 0;
	int y = 0;
	string itemName = "Locked Door";
public:
	string getItemName();
	char printinfo();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

class UnlockedDoor : public RoomItems
{
private:
	int x = 0;
	int y = 0;
	string itemName = "Unlocked Door";
public:
	string getItemName();
	char printinfo();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

class Chair : public RoomItems
{
private:
	int x = 12;
	int y = 7;
	string itemName = "Chair";
public:
	string getItemName();
	char printinfo();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

class Table : public RoomItems
{
private:
	int x = 13;
	int y = 7;
	string itemName = "Table Door";
public:
	string getItemName();
	char printinfo();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

class Bed : public RoomItems
{
private:
	int x = 10;
	int y = 5;
	string itemName = "Bed";
public:
	string getItemName();
	char printinfo();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

class Plant : public RoomItems
{
private:
	int x = 6;
	int y = 7;
	string itemName = "Plant";
public:
	string getItemName();
	char printinfo();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

class Light : public RoomItems
{
private:
	int x = 11;
	int y = 4;
	char item = '.';
	bool on = false;
	string itemName = "Light";
public:
	string getItemName();
	void setLightIcon(char);
	char getLightIcon();
	char printinfo();
	void turnLightsOn();
	void turnLightsOff();
	int getX();
	void setX(int);
	int getY();
	void setY(int);
};

#endif 