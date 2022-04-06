#pragma once

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cstring>
#include <string>
#include <Windows.h>
#include "Player.h"
#include "RoomItem.h"
#include "array"
#include "vector"
#include "RoomItem.h"

struct createRoomItemArray{
    // to make struct array of room item attribute
    int x;
    int y;
    char item;
};
#define MAP_SIZE 16
const int CHATBOX_SIZE = 6;
using namespace std;
class ChatBox;
class Player;
class Map {
    friend void printScreen(Map,ChatBox);
private:
    char mapping[MAP_SIZE][MAP_SIZE]{};
    char space = ' ';
    void createMap();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:
    Map();
    string isWhatItemAhead(Player);
    string checkMap(Player);
    string isOutOfBound(Player);
    string printItemAhead(string);
    void fillRoomItem(struct createRoomItemArray*);
    void printMap();
    void setItem(int, int, char);
    char getItem(int, int);
    void resetItem(int, int);
};

class ChatBox {
    friend void printScreen(Map,ChatBox);
private:
    char wall = '|';
    char space = ' ';
    const int messageLength = (MAP_SIZE * 3) - 2;
    char boxLines[CHATBOX_SIZE][(MAP_SIZE * 3) - 2]{};
    void createChatBox();
    void bumpMessage(int);
    void clearArray(int);
public:
    ChatBox();
    void printChatBox();
    void enterMessage(string);
    void enterMessage(string, string);
    void enterMessage(string, string, string);
    void enterMessage(string, string, string, string);
    void enterMessage(string, string, string, string, string);
    void enterMessage(string, string, string, string, string, string);
};

#endif 
