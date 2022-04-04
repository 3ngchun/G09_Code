#pragma once
#ifndef ROOMITEM_H
#define ROOMITEM_H

#include <iostream>

using namespace std;

class RoomItems
{
private:
	string itemName;
public:
	string getItemName();
	char printinfo();
};

class LockedDoor : public RoomItems
{
private:
	string itemName = "Locked Door";
public:
	string getItemName();
	char printinfo();
};

class UnlockedDoor : public RoomItems
{
private:
	string itemName = "Unlocked Door";
public:
	string getItemName();
	char printinfo();
};

class Chair : public RoomItems
{
private:
	string itemName = "Chair";
public:
	string getItemName();
	char printinfo();
};

class Table : public RoomItems
{
private:
	string itemName = "Table Door";
public:
	string getItemName();
	char printinfo();
};

class Bed : public RoomItems
{
private:
	string itemName = "Bed";
public:
	string getItemName();
	char printinfo();
};

class Plant : public RoomItems
{
private:
	string itemName = "Plant";
public:
	string getItemName();
	char printinfo();
};

class Light : public RoomItems
{
private:
	string itemName = "Light";
public:
	string getItemName();
	char printinfo();
};

#endif 