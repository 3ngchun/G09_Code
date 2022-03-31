#include <stdexcept>
#include "Player.h"
#include <iostream>

void Player::setName(string name) {
    this->name = name;
}

string Player::getName() {
    return name;
}

void Player::setX(int x) {
    this->x = x;
}

int Player::getX() {
    return x;
}

void Player::setY(int y) {
    this->y = y;
}

char Player::getPlayerIcon() {
    return player;
}

void Player::setPlayerIcon(char player) {
    this->player = player;
}

int Player::getY() {
    return y;
}

void Player::setDirection(string direction) {
    this->direction = direction;
}

string Player::getDirection() {
    return direction;
}

void Player::printName() {
    cout << "Hi, " << getName() << ", welcome..." << endl;
    cout << "are you ready to start your adventure?" << endl;
}

void Player::printPlayerIcon() {
    cout << getPlayerIcon() << endl;
}

void Player::printDirection() {
    if (direction == "up") {
        if (getX() != 0) {
            //chatBox.enterMessage("\nGo Up!");
            setX(getX() - 1);
        }
        else {
            //cout << "\nYou have bumped into a wall..." << endl;
        }
        setPlayerIcon('^');
    }
    else if (direction == "down") {
        if (getX() != 15) {
            //cout << "\nGo Down!" << endl;
            setX(getX() + 1);
        }
        else {
            //cout << "\nYou have bumped into a wall..." << endl;
        }
        setPlayerIcon('v');
    }
    else if (direction == "right") {
        if (getY() != 15) {
            //cout << "\nGo Right!" << endl;
            setY(getY() + 1);
        }
        else {
            //cout << "\nYou have bumped into a wall..." << endl;
        }
        setPlayerIcon('>');
    }
    else if (direction == "left") {
        if (getY() != 0) {
            //chatBox.enterMessage("Go Left!");
            setY(getY() - 1);
        }
        else {
            //cout << "\nYou have bumped into a wall..." << endl;
        }
        setPlayerIcon('<');
    }
    else if (direction == "giveup") {
        cout << "\nYou gave up... Exiting game.";
    }
    else {
        cout << "\nPlease enter one of the following: (Up/Down/Left/Right)" << endl;
        //cout << "Where do you want to go?" << endl;
    }
}