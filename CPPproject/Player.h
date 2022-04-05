#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
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
    string getDirection();
    void setDirection(string);
    int getX();
    void setX(int);
    int getY();
    void setY(int);
    char getPlayerIcon();
    void setPlayerIcon(char);
    void printDirection();
    void printName();
    void printPlayerIcon();
};

#endif 

