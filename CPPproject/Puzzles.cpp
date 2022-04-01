#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Puzzles.h"

void Puzzle::setUnsolved(){
    this -> solved = false;
}

void Puzzle::setSolved(){
    this -> solved = true;
}

bool Puzzle::getSolved(){
    return solved;
}

void Puzzle::setName(string name){
    this->puzzleName = name;
}

string Puzzle::getName(){
    return puzzleName;
}

void Puzzle::startPuzzle(){
    this->startPuzzle();
}

// Scrambled Letters Puzzle #1
void lettersPuzzle :: startPuzzle(){

    cout << "***Welcome to the Letters Puzzle!!***" << endl;

    while (input != correctAnswer){
        cout << endl;
        cout << "Decipher: " << scrambled << endl;
        cout << endl;
        cout << "Enter ')' to give up OR"<< endl;
        cout << "Enter your guess:";
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::toupper);
        if (input == ")"){
            cout << endl;
            cout << "You'll get it next time!!" << endl;
            break;
        }
    }

    if (input == correctAnswer){
        cout << endl;
        cout << "CONGRATULATIONS!!" << endl;
        cout << "You solved the puzzle!" << endl;
        cout << endl;
        this -> setSolved();
    }
}

// Arithmetic Puzzle #2
void arithmeticPuzzle :: startPuzzle(){

    cout << "***Welcome to the Arithmetic Puzzle!!***" << endl;

    while (input != correctAnswer){
        cout << endl;
        cout << "A farmer has 17 sheep and all but 8 die. How many are left?" << endl;
        cout << endl;
        cout << "Enter '69' to give up OR"<< endl;
        cout << "Enter your guess:";
        cin >> input;
        if (input == 69){
            cout << endl;
            cout << "You'll get it next time!!" << endl;
            break;
        }
    }

    if (input == correctAnswer){
        cout << endl;
        cout << "CONGRATULATIONS!!" << endl;
        cout << "You solved the puzzle!" << endl;
        cout << endl;
        this -> setSolved();
    }
}

//Lockbreaking Puzzle #3
void lockbreakingPuzzle :: startPuzzle(){

    cout << "***Welcome to the Lockbreaking Puzzle!!***" << endl;

    while (input != correctAnswer){
        cout << "Oh no! we've found an old password to a safe but we can't figure out what the missing number is :((" << endl;
        cout << "1 3 5 _ 9 11 13" << endl;
        cout << endl;
        cout << "Enter '69' to give up OR"<< endl;
        cout << "Enter your guess:";
        cin >> input;
        if (input == 69){
            cout << endl;
            cout << "You'll get it next time!!" << endl;
            break;
        }
    }

    if (input == correctAnswer){
        cout << endl;
        cout << "CONGRATULATIONS!!" << endl;
        cout << "You solved the puzzle!" << endl;
        cout << endl;
        this -> setSolved();
    }
}

// Riddle Puzzle #4
void riddlePuzzle :: startPuzzle(){

    cout << "**Lets solve a Riddle!!***" << endl;

    while (input != correctAnswer){
        cout << "If two is company, and three is a crowd, what are four and five?" << endl;
        cout << "Hint: the answer is an integer ;)" << endl;
        cout << endl;
        cout << "Enter '69' to give up OR"<< endl;
        cout << "Enter your guess:";
        cin >> input;
        if (input == 69){
            cout << endl;
            cout << "You'll get it next time!!" << endl;
            break;
        }
    }

    if (input == correctAnswer){
        cout << endl;
        cout << "CONGRATULATIONS!!" << endl;
        cout << "You solved the puzzle!" << endl;
        cout << endl;
        this -> setSolved();
    }
}

// Riddle Puzzle2 #5
void riddlePuzzle2 :: startPuzzle(){

    cout << "***Got another Riddle for ya!!***" << endl;

    while (input != correctAnswer){
        cout << endl;
        cout << "2 plus 2 is 4 minus 1 that's _?. QUICK MATHH" << endl;
        cout << endl;
        cout << "Enter '69' to give up OR"<< endl;
        cout << "Enter your guess:";
        cin >> input;
        if (input == 69){
            cout << endl;
            cout << "You'll get it next time!!" << endl;
            break;
        }
    }

    if (input == correctAnswer){
        cout << endl;
        cout << "CONGRATULATIONS!!" << endl;
        cout << "You solved the puzzle!" << endl;
        cout << endl;
        this -> setSolved();
    }
}

// Start random Puzzle function
void randomPuzzle(Puzzle *puzzles[]){
    int key;
    srand (time(NULL));
    key = (rand() % 5);
    Puzzle* curPuzzle = puzzles[key];

    if (curPuzzle->getSolved() == 0){
        curPuzzle->startPuzzle();
    } else {
        randomPuzzle(puzzles);
    }
}

bool unlockDoorCheck(Puzzle *puzzles[]){
    int flag;
    
    for(int i=0; i < 5; i++){
        if (puzzles[i]->getSolved() == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

//Puzzle *puzzles[5];

//lettersPuzzle puzzle1;
//arithmeticPuzzle puzzle2;
//lockbreakingPuzzle puzzle3;
//riddlePuzzle puzzle4;
//riddlePuzzle2 puzzle5;

//int main(){

//    puzzle1.setName("Letters Puzzle");
//    puzzle2.setName("Arithmetic Puzzle");
//    puzzle3.setName("Lockbreaking Puzzle");
//    puzzle4.setName("Riddle Puzzle 1");
//    puzzle5.setName("Riddle Puzzle 2");

//    puzzles[0] = &puzzle1;
//    puzzles[1] = &puzzle2;
//    puzzles[2] = &puzzle3;
//    puzzles[3] = &puzzle4;
//    puzzles[4] = &puzzle5;

//    do {
//        // for(int i=0; i < 5; i++) {  
//        // cout << puzzles[i]->getName() << "\n"; 
//        // cout << "Solved: " << puzzles[i]->getSolved() << "\n\n";  
//        // }
//        randomPuzzle(puzzles);
//    } while (unlockDoorCheck(puzzles) != 1);
    
//}