#include <stdexcept>
#include "Player.h"
#include <iostream>
#include <utility>
#include "Map.h"

void Player::setName(string name) {
    this->name = std::move(name);
}

string Player::getName() {
    return this->name;
}

void Player::setX(int x) {
    this->x = x;
}

int Player::getX() const {
    return this->x;
}

void Player::setY(int y) {
    this->y = y;
}

char Player::getPlayerIcon() const {
    return this->player;
}

void Player::setPlayerIcon(char player) {
    this->player = player;
}

int Player::getY() const {
    return this->y;
}

void Player::setDirection(string direction) {
    this->direction = std::move(direction);
}

string Player::printName() {
    string userName = "Hi " + getName() + ", welcome...";
    return userName;
}

void Player::userGuide() {
    cout << "USER INSTRUCTION GUIDE";
    cout << "\nDirection: up / down / left / right";
    cout << "\nGive up: quit";
    cout << "\nSolve all hidden puzzles and escape the room!\n";
}

void Player::printDirection(struct createRoomItemArray *roomItemArray) {
    if (this->direction == "up") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x && getY() == roomItemArray[i].y + 1) {
                setY(getY());
                checked = true;
                break;
            }
        }
        if (getY() != 0 && !checked) {
            setY(getY() - 1);
        }
        setPlayerIcon('^');
    } else if (this->direction == "down") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x && getY() == roomItemArray[i].y - 1) {
                setY(getY());
                checked = true;
                break;
            }
        }
        if (getY() != 15 && !checked) {
            setY(getY() + 1);
        }
        setPlayerIcon('v');
    } else if (this->direction == "right") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x - 1 && getY() == roomItemArray[i].y) {
                setY(getY());
                checked = true;
                break;
            }
        }
        if (getX() != 15 && !checked) {
            setX(getX() + 1);
        }
        setPlayerIcon('>');
    } else if (this->direction == "left") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x + 1 && getY() == roomItemArray[i].y) {
                setY(getY());
                checked = true;
                break;
            }
        }
        if (getX() != 0 && !checked) {
            setX(getX() - 1);
        }
        setPlayerIcon('<');
    }
}

istream &operator>>(istream &in, Player &player) {
    string ERROR_MSG;
    cout << "But first, we would like to know your name: ";
    getline(in, player.name);
    int length = (int) player.name.length();
    for (int i = 0; i < length; i++) {
        if (!((player.name[i] >= 48 && player.name[i] <= 57) ||
              (player.name[i] >= 65 && player.name[i] <= 90) ||
              (player.name[i] >= 97 && player.name[i] <= 122))) {
            ERROR_MSG = "Name cannot contain special character.";
            throw invalid_argument(ERROR_MSG);
        }
    }
    if (length > 15) {
        ERROR_MSG = "Name should not exceed 15 characters";
        throw length_error(ERROR_MSG);
    }
    return in;
}