#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Puzzles.h"

void Puzzle::setUnsolved() {
    this->solved = false;
}

void Puzzle::setSolved() {
    this->solved = true;
}

bool Puzzle::getSolved() {
    return solved;
}

void Puzzle::setName(string name) {
    this->puzzleName = name;
}

string Puzzle::getName() {
    return puzzleName;
}

void Puzzle::startPuzzle(ChatBox* cb, Map map) {
    this->startPuzzle(cb, map);
}

// Scrambled Letters Puzzle #1
lettersPuzzle::lettersPuzzle() {
    setName("Letters Puzzle");
}

void lettersPuzzle::startPuzzle(ChatBox* cb, Map map) {
    string input;

    cb->enterMessage("***Welcome to the Letters Puzzle!!***");

    while (true) {
        cb->enterMessage("", "Decipher: " + scrambled);
        cb->enterMessage("Enter ')' to give up OR", "");
        // cb->enterMessage("Enter your guess:");
        system("CLS");
        map.printMap();
        cb->printChatBox();
        cout << "\nEnter your guess: ";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        if (input == ")") {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (input == correctAnswer) {
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();

            break;
        }
    }
}

// Arithmetic Puzzle #2
arithmeticPuzzle::arithmeticPuzzle() {
    setName("Arithmetic Puzzle");
}

void arithmeticPuzzle::startPuzzle(ChatBox* cb, Map map) {
    string input;
    int int_input;

    cb->enterMessage("***Welcome to the Arithmetic Puzzle!!***");

    while (true) {
        cb->enterMessage("", "A farmer has 17 sheep and all but 8 die.");
        cb->enterMessage("How many are left?");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        map.printMap();
        cb->printChatBox();
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception& err)
        {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

//Lockbreaking Puzzle #3
lockbreakingPuzzle::lockbreakingPuzzle() {
    setName("Lockbreaking Puzzle");
}

void lockbreakingPuzzle::startPuzzle(ChatBox* cb, Map map) {

    string input;
    int int_input;

    cb->enterMessage("***Welcome to the Lockbreaking Puzzle!!***");

    while (true) {
        cb->enterMessage("", "We've found an incomplete password!!");
        cb->enterMessage("1 3 5 _ 9 11 13");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        map.printMap();
        cb->printChatBox();
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception& err)
        {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

// Riddle Puzzle #4
riddlePuzzle::riddlePuzzle() {
    setName("Riddle Puzzle");
}

void riddlePuzzle::startPuzzle(ChatBox* cb, Map map) {

    string input;
    int int_input;

    cb->enterMessage("***Lets solve a Riddle!!***");

    while (true) {
        cb->enterMessage("If two is company, and three is a crowd,");
        cb->enterMessage("what are four and five?");
        cb->enterMessage("Hint: the answer is an integer ;)");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        map.printMap();
        cb->printChatBox();
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception& err)
        {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

// Riddle Puzzle2 #5
riddlePuzzle2::riddlePuzzle2() {
    setName("Riddle Puzzle 2");
}

void riddlePuzzle2::startPuzzle(ChatBox* cb, Map map) {

    string input;
    int int_input;

    cb->enterMessage("***Got another Riddle for ya!!***");

    while (true) {
        cb->enterMessage("", "2 plus 2 is 4, minus 1 that's _?.");
        cb->enterMessage("QUICKKK MATHHHH");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        map.printMap();
        cb->printChatBox();
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception& err)
        {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

void initPuzzles(Puzzle* puzzles[]) {

    lettersPuzzle* p1 = new lettersPuzzle();
    arithmeticPuzzle* p2 = new arithmeticPuzzle();
    lockbreakingPuzzle* p3 = new lockbreakingPuzzle();
    riddlePuzzle* p4 = new riddlePuzzle();
    riddlePuzzle2* p5 = new riddlePuzzle2();

    puzzles[0] = p1;
    puzzles[1] = p2;
    puzzles[2] = p3;
    puzzles[3] = p4;
    puzzles[4] = p5;
}

int numPuzzleSolved(Puzzle* puzzles[]) {
    int solvedPuzzles = 0;
    Puzzle* currPuzzle;

    for (int i = 0; i < 5; i++) {
        currPuzzle = puzzles[i];
        if (currPuzzle->getSolved() == true) {
            solvedPuzzles++;
        }
        else {
            continue;
        }
    }
    return solvedPuzzles;
}

void randomPuzzle(Puzzle* puzzles[], ChatBox* cb, Map map) {
    int key;
    //srand(time(NULL));
    key = (rand() % 5);
    Puzzle* curPuzzle = puzzles[key];

    if (curPuzzle->getSolved() == 0) {
        curPuzzle->startPuzzle(cb, map);
    }
    else {
        randomPuzzle(puzzles, cb, map);
    }
}

int unlockDoorCheck(Puzzle* puzzles[]) {
    int flag = 1;
    Puzzle* currPuzzle;

    for (int i = 0; i < 5; i++) {
        currPuzzle = puzzles[i];
        if (currPuzzle->getSolved() == false) {
            flag = 0;
            break;
        }
        else {
            continue;
        }
    }
    return flag;
}