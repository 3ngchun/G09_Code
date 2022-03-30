#include <iostream>
#include <string>

using namespace std;

class Player {
protected:
    string direction;
    string name;
public:
    void setName(string);
    string getName();
    string getDirection();
    void setDirection(string);
    void printDirection();
    void printName();
};

void Player::setName(string name) {
    this->name = name;
}
string Player::getName() {
    return name;
}

string Player::getDirection() {
    return direction;
}

void Player::setDirection(string direction) {
    this->direction = direction;
}

void Player::printName() {
    cout << "Hi, " << getName() << ", welcome..."  << endl;
    cout << "are you ready to start your adventure?" << endl;
}

void Player::printDirection() {
    if (direction == "up") {
        cout << "\nGo Up!" << endl;
    }
    else if (direction == "down") {
        cout << "\nGo Down!" << endl;
    }
    else if (direction == "right") {
        cout << "\nGo Right!" << endl;
    }
    else if (direction == "left") {
        cout << "\nGo Left!" << endl;
    }
    else if (direction == "giveup") {
        cout << "\nYou gave up... Exiting game.";
    }
    else {
        cout << "\nPlease enter one of the following: (Up/Down/Left/Right)" << endl;
        //cout << "Where do you want to go?" << endl;
    }
}

int main() {
    string direction;
    string name;
    Player player;

    cout << "Hi Adventurer, welcome to QuizLand!" << endl;
    cout << "But first, we would like to know your name: ";

    getline(cin, name);
    player.setName(name);
    player.printName();

    do {
        cout << "Where do you want to go? (Up/Down/Left/Right)" << endl;
        cin >> direction;
        int length = direction.length();
        for (int i = 0; i < length; i++) {
            int c = direction[i];
            direction[i] = tolower(c);
        }
        player.setDirection(direction);
        player.printDirection();
    } while (player.getDirection() != "giveup");

    return 0;
}