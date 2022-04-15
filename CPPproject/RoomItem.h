#pragma once
#ifndef ROOMITEM_H
#define ROOMITEM_H

#include <iostream>

using namespace std;

class RoomItems
{
private:
	char item{};
	int x = 0;
	int y = 0;
public:
	virtual char printinfo() const;
    virtual int getX() const;
    virtual void setX(int);
    virtual int getY() const;
    virtual void setY(int);
};

class LockedDoor : public RoomItems
{
private:
	int x = 0;
	int y = 0;
    char item = ']';
public:
	char printinfo() const;
	int getX() const override;
	void setX(int) override;
	int getY() const override;
	void setY(int) override;
};

class UnlockedDoor : public RoomItems
{
private:
	int x = 0;
	int y = 0;
    char item = '[';
public:
	char printinfo() const;
	int getX() const override;
	void setX(int) override;
	int getY() const override;
	void setY(int) override;
};

class Chair : public RoomItems
{
private:
	int x = 12;
	int y = 7;
    char item = 'h';
public:
	char printinfo() const;
	int getX() const override;
	void setX(int) override;
	int getY() const override;
	void setY(int) override;
};

class Table : public RoomItems
{
private:
	int x = 13;
	int y = 7;
    char item = 'T';
public:
	char printinfo() const;
	int getX() const override;
	void setX(int) override;
	int getY() const override;
	void setY(int);
};

class Bed : public RoomItems
{
private:
	int x = 10;
	int y = 5;
    char item = '=';
public:
	char printinfo() const ;
	int getX() const override;
	void setX(int) override;
	int getY() const override;
	void setY(int) override;
};

class Plant : public RoomItems
{
private:
	int x = 6;
	int y = 7;
	char item = '+';
public:
	char printinfo() const;
	int getX() const override;
	void setX(int) override;
	int getY() const override;
	void setY(int) override;
};

class Light : public RoomItems
{
private:
	int x = 11;
	int y = 4;
	char item = '*';
public:
	char printinfo() const;
	int getX() const override;
	void setX(int) override;
	int getY() const override;
	void setY(int);
};

#endif 
