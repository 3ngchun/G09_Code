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
    void setSolved();
    bool getSolved() const;
    void setName(string);
    string getName() const;
    virtual void startPuzzle(ChatBox*, Map);
};

class lettersPuzzle : public Puzzle {
private:
    string correctAnswer = "PROGRAMMING";
    string scrambled = "GAPMGNIRORM";
public:
    lettersPuzzle();
    void startPuzzle(ChatBox*, Map) override;
};

class arithmeticPuzzle : public Puzzle {
private:
    int correctAnswer = 8;
public:
    arithmeticPuzzle();
    void startPuzzle(ChatBox*, Map) override;
};

class lockbreakingPuzzle : public Puzzle {
private:
    int correctAnswer = 7;
public:
    lockbreakingPuzzle();
    void startPuzzle(ChatBox*, Map) override;
};

class riddlePuzzle : public Puzzle {
private:
    int correctAnswer = 9;
public:
    riddlePuzzle();
    void startPuzzle(ChatBox*, Map) override;
};

class riddlePuzzle2 : public Puzzle {
private:
    int correctAnswer = 3;
public:
    riddlePuzzle2();
    void startPuzzle(ChatBox*, Map) override;
};

// init child puzzles
void initPuzzles(Puzzle* puzzles[]);

// pseudo random generator
double getRand(double);

// Start random Puzzle function
void randomPuzzle(Puzzle* puzzles[], ChatBox* cb, Map map);

// check num puzzles solved
int numPuzzleSolved(Puzzle* puzzles[]);

// check all puzzles solved, unlock door
int unlockDoorCheck(Puzzle* puzzles[]);

#endif 