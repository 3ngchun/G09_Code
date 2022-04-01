#pragma once
#ifndef ROOMITEM_H
#define ROOMITEM_H

#include <iostream>

using namespace std;

class RoomItems
{
public:
	char printinfo();
};

class LockedDoor : public RoomItems
{
public:
	char printinfo();
};

class UnlockedDoor : public RoomItems
{
public:
	char printinfo();
};

class Chair : public RoomItems
{
public:
	char printinfo();
};

class Table : public RoomItems
{
public:
	char printinfo();
};

class Bed : public RoomItems
{
public:
	char printinfo();
};

class Plant : public RoomItems
{
public:
	char printinfo();
};

class Light : public RoomItems
{
public:
	char printinfo();
};

#endif 