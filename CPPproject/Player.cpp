#include <stdexcept>
#include "Player.h"
#include "RoomItem.h"
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
    cout << "Hi " << getName() << ", welcome..." << endl;
    cout << "\nUser Instruction Guide:";
    cout << "\nDirection: up / down / left / right";
    cout << "\nGive up: quit";
    cout << "\nInteract with all room items to solve puzzles and escape the room!\n";
}

void Player::printPlayerIcon() {
    cout << getPlayerIcon() << endl;
}

void Player::printDirection() {
    LockedDoor ld;
    UnlockedDoor ud;
    Table t;
    Chair c;
    Bed b;
    Plant p;
    Light l;
    if (direction == "up") {
        if ((getX() == ld.getX() && getY() == ld.getY() + 1)
            || (getX() == t.getX() && getY() == t.getY() + 1)
            || (getX() == c.getX() && getY() == c.getY() + 1)
            || (getX() == ud.getX() && getY() == ud.getY() + 1)
            || (getX() == p.getX() && getY() == p.getY() + 1)
            || (getX() == b.getX() && getY() == b.getY() + 1)
            || (getX() == l.getX() && getY() == l.getY() + 1)) {
            setY(getY());
        }
        else if (getY() != 0) {
            //chatBox.enterMessage("\nGo Up!");
            setY(getY() - 1);
        }
        else {
            //cout << "\nYou have bumped into a wall..." << endl;
        }
        setPlayerIcon('^');
    }
    else if (direction == "down") {
        if ((getX() == ld.getX() && getY() == ld.getY() - 1)
            || (getX() == t.getX() && getY() == t.getY() - 1)
            || (getX() == c.getX() && getY() == c.getY() - 1)
            || (getX() == ud.getX() && getY() == ud.getY() - 1)
            || (getX() == p.getX() && getY() == p.getY() - 1)
            || (getX() == b.getX() && getY() == b.getY() - 1)
            || (getX() == l.getX() && getY() == l.getY() - 1)) {
            setY(getY());
        }
        else if (getY() != 15) {
            //cout << "\nGo Down!" << endl;
            setY(getY() + 1);
        }
        else {
            //cout << "\nYou have bumped into a wall..." << endl;
        }
        setPlayerIcon('v');
    }
    else if (direction == "right") {
        if ((getX() == ld.getX() - 1 && getY() == ld.getY())
            || (getX() == t.getX() - 1 && getY() == t.getY())
            || (getX() == c.getX() - 1 && getY() == c.getY())
            || (getX() == ud.getX() - 1 && getY() == ud.getY())
            || (getX() == p.getX() - 1 && getY() == p.getY())
            || (getX() == b.getX() - 1 && getY() == b.getY())
            || (getX() == l.getX() - 1 && getY() == l.getY())) {
            setY(getY());
        }
        else if (getX() != 15) {
            //cout << "\nGo Right!" << endl;
            setX(getX() + 1);
        }
        else {
            //cout << "\nYou have bumped into a wall..." << endl;
        }
        setPlayerIcon('>');
    }
    else if (direction == "left") {
        if ((getX() == ld.getX() + 1 && getY() == ld.getY())
            || (getX() == t.getX() + 1 && getY() == t.getY())
            || (getX() == c.getX() + 1 && getY() == c.getY())
            || (getX() == ud.getX() + 1 && getY() == ud.getY())
            || (getX() == p.getX() + 1 && getY() == p.getY())
            || (getX() == b.getX() + 1 && getY() == b.getY())
            || (getX() == l.getX() + 1 && getY() == l.getY())) {
            setY(getY());
        }
        else if (getX() != 0) {
            //chatBox.enterMessage("Go Left!");
            setX(getX() - 1);
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

istream& operator >> (istream& in, Player& player) {
    const string ERROR_MSG = "Name cannot contain special character.";
    cout << "But first, we would like to know your name: ";
    getline(in, player.name);
    int length = player.name.length();
    for (int i = 0; i < length; i++) {
        if (!((player.name[i] >= 48 && player.name[i] <= 57) ||
            (player.name[i] >= 65 && player.name[i] <= 90) ||
            (player.name[i] >= 97 && player.name[i] <= 122))) {
            throw(ERROR_MSG);
        }
    }
    if (length > 15) {
        throw(length);
    }
    return in;
}