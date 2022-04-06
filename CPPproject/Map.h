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
    string printItemAhead(string next_facing_item);
    void fillRoomItem(struct createRoomItemArray*);
    void printMap();
    void setItem(int x, int y, char item);
    char getItem(int x, int y);
    void resetItem(int x, int y);
};

class ChatBox {
    friend void printScreen(Map,ChatBox);
private:
    char wall = '|';
    char space = ' ';
    const int messageLength = (MAP_SIZE * 3) - 2;
    char boxLines[CHATBOX_SIZE][(MAP_SIZE * 3) - 2]{};
    void createChatBox();
    void bumpMessage(int lines);
    void clearArray(int lines);
public:
    ChatBox();
    void printChatBox();
    void enterMessage(string line1);
    void enterMessage(string line1, string line2);
    void enterMessage(string line1, string line2, string line3);
    void enterMessage(string line1, string line2, string line3, string line4);
    void enterMessage(string line1, string line2, string line3, string line4, string line5);
    void enterMessage(string line1, string line2, string line3, string line4, string line5, string line6);
};

#endif 
