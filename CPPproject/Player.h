#pragma once

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Map.h"

using namespace std;

class Player {
    friend istream& operator >> (istream&, Player&);
private:
    string direction;
    string name;
    int x = 15;
    int y = 15;
    char player = '^';
public:
    string getName();
    void setName(string);
    void setDirection(string);
    int getX() const;
    void setX(int);
    int getY() const;
    void setY(int);
    char getPlayerIcon() const;
    void setPlayerIcon(char);
    void printDirection(struct createRoomItemArray*);
    string printName();
    static void userGuide();
};

#endif 

