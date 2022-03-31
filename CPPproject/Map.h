#pragma once

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <cstring>
#include <string>

#define MAP_SIZE 16
const int CHATBOX_SIZE = 6;
using namespace std;

class Map {
private:
    char mapping[MAP_SIZE][MAP_SIZE]{};
    char space = ' ';
    void createMap();

public:
    Map();
    void printMap();
    void setItem(int x, int y, char item);
    void resetItem(int x, int y);
};

class ChatBox {
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
    // one line intake
    void enterMessage(string line1);
    // two line intake
    void enterMessage(string line1, string line2);
    // three line intake
    void enterMessage(string line1, string line2, string line3);
    // four line intake
    void enterMessage(string line1, string line2, string line3, string line4);
    // five line intake
    void enterMessage(string line1, string line2, string line3, string line4, string line5);
    // six line intake (max)
    void enterMessage(string line1, string line2, string line3, string line4, string line5, string line6);
    void printChatBox();
};

#endif 