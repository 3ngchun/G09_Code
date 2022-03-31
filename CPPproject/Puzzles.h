#pragma once
#ifndef PUZZLES_H
#define PUZZLES_H

#include <iostream>

using namespace std;

class Puzzle{
    private:
        bool solved = false;
        string puzzleName;
    public:
        void setUnsolved();
        void setSolved();
        bool getSolved();
        void setName(string);
        string getName();
        virtual void startPuzzle();
};

class lettersPuzzle : public Puzzle{
    private:
        string correctAnswer = "PROGRAMMING";
        string scrambled = "GAPMGNIRORM";
        string input;
    public:
        void startPuzzle();
};

class arithmeticPuzzle : public Puzzle{
    private:
        int correctAnswer = 8;
        int input;
    public:
        void startPuzzle();
};

class lockbreakingPuzzle : public Puzzle{
    private:
        int correctAnswer = 7;
        int input;
    public:
        void startPuzzle();
};

class riddlePuzzle : public Puzzle{
    private:
        int correctAnswer = 9;
        int input;
    public:
        void startPuzzle();
};

class riddlePuzzle2 : public Puzzle{
        private:
        int correctAnswer = 3;
        int input;
    public:
        void startPuzzle();
};
