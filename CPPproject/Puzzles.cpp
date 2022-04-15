#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Puzzles.h"
#include <random>
#include <chrono>
#include <utility>
#include "cmath"

void Puzzle::setSolved() {
    this->solved = true;
}

bool Puzzle::getSolved() const { //getter for solved boolean
    return this->solved;
}

void Puzzle::setName(string name) { //setter for puzzle name
    this->puzzleName = std::move(name);
}

string Puzzle::getName() const {
    return this->puzzleName;
}

void Puzzle::startPuzzle(ChatBox *cb, Map map) {
    //method to start puzzle
    this->startPuzzle(cb, map);
}

// Scrambled Letters Puzzle #1
// Player is to decipher a scrambled letters text into a word
lettersPuzzle::lettersPuzzle() {
    setName("Letters Puzzle");
}

void lettersPuzzle::startPuzzle(ChatBox *cb, Map map) {
    string input;
    string msg = "***Welcome to the " + Puzzle::getName() + "!!***";
    cb->enterMessage(msg);
    while (true) {
        cb->enterMessage("", "Decipher: " + this->scrambled);
        cb->enterMessage("Enter ')' to give up OR", "");
        system("CLS");
        Player::userGuide();
        printScreen(map, *cb);  // game background
        cout << "\nEnter your guess: ";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        if (input == ")") {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (input == this->correctAnswer) {
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

// Arithmetic Puzzle #2
// Player to solve a simple arithmetic puzzle
arithmeticPuzzle::arithmeticPuzzle() {
    setName("Arithmetic Puzzle");
}

void arithmeticPuzzle::startPuzzle(ChatBox *cb, Map map) {
    string input;
    int int_input;
    string msg = "***Welcome to the " + Puzzle::getName() + "!!***";
    cb->enterMessage(msg);
    while (true) {
        cb->enterMessage("", "A farmer has 17 sheep and all but 8 die.");
        cb->enterMessage("How many are left?");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        Player::userGuide();
        printScreen(map, *cb);  // game background
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception &err) {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == this->correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

//Lockbreaking Puzzle #3
//Player to decipher the missing piece to a numerical password
lockbreakingPuzzle::lockbreakingPuzzle() {
    setName("Lockbreaking Puzzle");
}

void lockbreakingPuzzle::startPuzzle(ChatBox *cb, Map map) {
    string input;
    int int_input;
    string msg = "***Welcome to the " + Puzzle::getName() + "!!***";
    cb->enterMessage(msg);
    while (true) {
        cb->enterMessage("", "We've found an incomplete password!!");
        cb->enterMessage("1 3 5 _ 9 11 13");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        Player::userGuide();
        printScreen(map, *cb);  // game background
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception &err) {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == this->correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

// Riddle Puzzle #4
// Player to decipher a simple riddle
riddlePuzzle::riddlePuzzle() {
    setName("Riddle Puzzle");
}

void riddlePuzzle::startPuzzle(ChatBox *cb, Map map) {
    string input;
    int int_input;
    string msg = "***Welcome to the " + Puzzle::getName() + "!!***";
    cb->enterMessage(msg);
    while (true) {
        cb->enterMessage("If two is company, and three is a crowd,");
        cb->enterMessage("what are four and five?");
        cb->enterMessage("Hint: the answer is an integer ;)");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        Player::userGuide();
        printScreen(map, *cb);  // game background
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception &err) {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == this->correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

// Riddle Puzzle2 #5
// Second riddle for player to decipher
riddlePuzzle2::riddlePuzzle2() {
    setName("Riddle Puzzle 2");
}

void riddlePuzzle2::startPuzzle(ChatBox *cb, Map map) {
    string input;
    int int_input;
    string msg = "***Welcome to the " + Puzzle::getName() + "!!***";
    cb->enterMessage(msg);
    while (true) {
        cb->enterMessage("", "2 plus 2 is 4, minus 1 that's _?.");
        cb->enterMessage("QUICKKK MATHHHH");
        cb->enterMessage("", "Enter '69' to give up OR");
        system("CLS");
        Player::userGuide();
        printScreen(map, *cb);  // game background
        cout << "\nEnter your guess: ";
        getline(cin, input);
        try {
            int_input = stoi(input);
        }
        catch (exception &err) {
            cb->enterMessage("Please enter an integer");
        }
        if (int_input == 69) {
            cb->enterMessage("", "You'll get it next time!!");
            break;
        }
        if (int_input == this->correctAnswer) {
            cout << endl;
            cb->enterMessage("", "", "", "CONGRATULATIONS!!");
            cb->enterMessage("", "You solved the puzzle!");
            this->setSolved();
            break;
        }
    }
}

// Method to intialize all child puzzles and include them in a array of puzzles
void initPuzzles(Puzzle *puzzles[]) {
    auto *p1 = new lettersPuzzle();
    auto *p2 = new arithmeticPuzzle();
    auto *p3 = new lockbreakingPuzzle();
    auto *p4 = new riddlePuzzle();
    auto *p5 = new riddlePuzzle2();
    puzzles[0] = p1;
    puzzles[1] = p2;
    puzzles[2] = p3;
    puzzles[3] = p4;
    puzzles[4] = p5;
}

// Method to check for the number of puzzles solved
int numPuzzleSolved(Puzzle *puzzles[]) {
    int solvedPuzzles = 0;
    Puzzle *currPuzzle;
    for (int i = 0; i < 5; i++) {
        currPuzzle = puzzles[i];
        if (currPuzzle->getSolved()) {
            solvedPuzzles++;
        } else {
            continue;
        }
    }
    return solvedPuzzles;
}

// pseudo random generator
double getRand(double range) {
    auto start = std::chrono::high_resolution_clock::now();
    using namespace std;
    random_device crypto_random_generator;
    auto finish = chrono::high_resolution_clock::now();
    mt19937 actual_distribution(crypto_random_generator() * time(nullptr) +
                                chrono::duration_cast<chrono::nanoseconds>(finish - start).count());
    uniform_real_distribution<double> dist(0, range);
    return dist(actual_distribution);
}

//method to call a random puzzle, is called when player interacts with room item
void randomPuzzle(Puzzle *puzzles[], ChatBox *cb, Map map) {
    int key;
    key = lround(getRand(5));
    Puzzle *curPuzzle = puzzles[key];
    if (curPuzzle->getSolved() == 0) {
        curPuzzle->startPuzzle(cb, map);
    } else {
        randomPuzzle(puzzles, cb, map);
    }
}

// method to check if all puzzles are solved and if door should be unlocked
int unlockDoorCheck(Puzzle *puzzles[]) {
    int flag = 1;
    Puzzle *currPuzzle;
    for (int i = 0; i < 5; i++) {
        currPuzzle = puzzles[i];
        if (!currPuzzle->getSolved()) {
            flag = 0;
            break;
        } else {
            continue;
        }
    }
    return flag;
}