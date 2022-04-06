#pragma once
#ifndef PUZZLES_H
#define PUZZLES_H

#include <iostream>
#include "Map.h"

using namespace std;

class Puzzle {
private:
    bool solved = false;
    string puzzleName;
public:
    void setUnsolved();
    void setSolved();
    bool getSolved();
    void setName(string);
    string getName();
    virtual void startPuzzle(ChatBox*, Map);
};

class lettersPuzzle : public Puzzle {
private:
    string correctAnswer = "PROGRAMMING";
    string scrambled = "GAPMGNIRORM";
public:
    lettersPuzzle();
    void startPuzzle(ChatBox*, Map);
};

class arithmeticPuzzle : public Puzzle {
private:
    int correctAnswer = 8;
    int input;
public:
    arithmeticPuzzle();
    void startPuzzle(ChatBox*, Map);
};

class lockbreakingPuzzle : public Puzzle {
private:
    int correctAnswer = 7;
    int input;
public:
    lockbreakingPuzzle();
    void startPuzzle(ChatBox*, Map);
};

class riddlePuzzle : public Puzzle {
private:
    int correctAnswer = 9;
    int input;
public:
    riddlePuzzle();
    void startPuzzle(ChatBox*, Map);
};

class riddlePuzzle2 : public Puzzle {
private:
    int correctAnswer = 3;
    int input;
public:
    riddlePuzzle2();
    void startPuzzle(ChatBox*, Map);
};

// init child puzzles
void initPuzzles(Puzzle* puzzles[]);

// Start random Puzzle function
void randomPuzzle(Puzzle* puzzles[], ChatBox* cb, Map map);

// check num puzzles solved
int numPuzzleSolved(Puzzle* puzzles[]);

// check all puzzles solved, unlock door
int unlockDoorCheck(Puzzle* puzzles[]);

#endif 