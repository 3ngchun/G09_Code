#include <stdexcept>
#include "Player.h"
#include "RoomItem.h"
#include <iostream>
#include "Map.h"

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
    cout << "Hi " << getName() << ", welcome..." << endl;
    cout << "\nUser Instruction Guide:";
    cout << "\nDirection: up / down / left / right";
    cout << "\nGive up: quit";
    cout << "\nInteract with all room items to solve puzzles and escape the room!\n";
}

void Player::printPlayerIcon() {
    cout << getPlayerIcon() << endl;
}

void Player::printDirection(struct createRoomItemArray *roomItemArray) {
    LockedDoor ld;
    UnlockedDoor ud;
    Table t;
    Chair c;
    Bed b;
    Plant p;
    Light l;
    if (direction == "up") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x && getY() == roomItemArray[i].y+1) {
                setY(getY());
                checked = true;
                break;
            }
        }
        if (getY() != 0 && !checked) {
            setY(getY() - 1);
        }
        setPlayerIcon('^');
    } else if (direction == "down") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x && getY() == roomItemArray[i].y-1) {
                setY(getY());
                checked = true;
                break;
            }
        }
        if (getY() != 15 && !checked) {
            setY(getY() + 1);
        } else { ;
        }
        setPlayerIcon('v');
    } else if (direction == "right") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x -1 && getY() == roomItemArray[i].y) {
                setY(getY());
                checked = true;
                break;
            }
        }
        if (getX() != 15 && !checked) {
            setX(getX() + 1);
        }
        setPlayerIcon('>');
    } else if (direction == "left") {
        bool checked = false;
        for (int i = 0; i < 6; i++) {
            if (getX() == roomItemArray[i].x +1 && getY() == roomItemArray[i].y) {
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
    const string ERROR_MSG = "Name cannot contain special character.";
    cout << "But first, we would like to know your name: ";
    getline(in, player.name);
    int length = player.name.length();
    for (int i = 0; i < length; i++) {
        if (!((player.name[i] >= 48 && player.name[i] <= 57) ||
              (player.name[i] >= 65 && player.name[i] <= 90) ||
              (player.name[i] >= 97 && player.name[i] <= 122))) {
            throw (ERROR_MSG);
        }
    }
    if (length > 15) {
        throw (length);
    }
    return in;
}