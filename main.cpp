#include <iostream>
#include <cstring>
#include <string>

#define MAP_SIZE 16
const int CHATBOX_SIZE = 6;
using namespace std;

class ChatBox;

class Player {
private:
    string direction;
    string name;
    int x = 15;
    int y = 15;
    char player = '^';
public:
    string getName();
    void setName(string);
    string getDirection();
    void setDirection(string);
    int getX();
    void setX(int);
    int getY();
    void setY(int);
    char getPlayerIcon();
    void setPlayerIcon(char);
    void printDirection();
    void printName();
    void printPlayerIcon();
};

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

class Map {
private:
    char mapping[MAP_SIZE][MAP_SIZE]{};
    char space = ' ';
    void createMap() {
        for (auto& i : this->mapping) {
            for (char& j : i) {
                j = this->space;
            }
        }
    }

public:
    Map() {
        createMap();
    }

    void printMap() {
        for (auto& i : mapping) {
            for (int j = 0; j < MAP_SIZE; j++) {
                if (j % 16 == 0) {
                    printf("\n");
                }
                printf("[%c]", i[j]);
            }
        }
    }

    void setItem(int x, int y, char item) {
        // set x,y position to item char
        this->mapping[x][y] = item;
    }

    void resetItem(int x, int y) {
        // reset x,y position back to space
        this->mapping[x][y] = this->space;
    }
};

class ChatBox {
private:
    char wall = '|';
    char space = ' ';
    const int messageLength = (MAP_SIZE * 3) - 2;
    char boxLines[CHATBOX_SIZE][(MAP_SIZE * 3) - 2]{};
    void createChatBox() {
        // initialise chatBox
        for (auto& i : this->boxLines) {
            for (int j = 0; j < this->messageLength; j++) {
                i[j] = this->space;
            }
        }
        printf("\n-------------------chat-box---------------------\n");  //49
        for (auto& i : this->boxLines) {
            printf("%c", this->wall);
            for (int j = 0; j < this->messageLength; j++) {
                printf("%c", i[j]);
            }
            printf("%c\n", this->wall);
        }
        printf("------------------------------------------------");
        system("CLS");
    }
    void bumpMessage(int lines) {
        for (int i = 0; i < CHATBOX_SIZE - lines; i++) {
            // move all message up
            copy(begin(this->boxLines[i + lines]), end(this->boxLines[i + lines]), begin(this->boxLines[i]));
        }
    }
    void clearArray(int lines) {
        for (int i = 1; i < lines + 1; i++) {
            // clear array for new lines
            fill_n(this->boxLines[CHATBOX_SIZE - i], this->messageLength, this->space);  // clear last line
        }
    }

public:
    ChatBox() {
        createChatBox();
    }
    // one line intake
    void enterMessage(string line1) {
        const int lines = 1;
        struct getLineArray {
            string line;
            int lineLength{};
        };
        getLineArray lineArray[lines];
        lineArray[0].line = line1;
        lineArray[0].lineLength = line1.length();

        bumpMessage(lines); // push history chat up
        clearArray(lines); // clear off unwanted text on new lines
        struct counter {
            int chatBoxStartPoint;
        };
        counter counts{};
        counts.chatBoxStartPoint = CHATBOX_SIZE - lines;
        for (int i = 0; i < lines; i++) {
            // for each line
            for (int j = 0; j < lineArray[i].lineLength; j++) {
                // add message to new lines
                if (j == this->messageLength) {
                    break;
                }
                this->boxLines[counts.chatBoxStartPoint][j] = lineArray[i].line[j];
            }
            counts.chatBoxStartPoint++;
        }
    }
    // two line intake
    void enterMessage(string line1, string line2) {
        const int lines = 2;
        struct getLineArray {
            string line;
            int lineLength{};
        };
        struct getLineArray lineArray[lines];
        lineArray[0].line = line1;
        lineArray[0].lineLength = line1.length();
        lineArray[1].line = line2;
        lineArray[1].lineLength = line2.length();

        bumpMessage(lines); // push history chat up
        clearArray(lines); // clear off unwanted text on new lines
        struct counter {
            int chatBoxStartPoint;
        };
        counter counts{};
        counts.chatBoxStartPoint = CHATBOX_SIZE - lines;
        for (int i = 0; i < lines; i++) {
            // for each line
            for (int j = 0; j < lineArray[i].lineLength; j++) {
                // add message to new lines
                if (j == this->messageLength) {
                    break;
                }
                this->boxLines[counts.chatBoxStartPoint][j] = lineArray[i].line[j];
            }
            counts.chatBoxStartPoint++;
        }
    }
    // three line intake
    void enterMessage(string line1, string line2, string line3) {
        const int lines = 3;
        struct getLineArray {
            string line;
            int lineLength{};
        };
        struct getLineArray lineArray[lines];
        lineArray[0].line = line1;
        lineArray[0].lineLength = line1.length();
        lineArray[1].line = line2;
        lineArray[1].lineLength = line2.length();
        lineArray[2].line = line3;
        lineArray[2].lineLength = line3.length();

        bumpMessage(lines); // push history chat up
        clearArray(lines); // clear off unwanted text on new lines
        struct counter {
            int chatBoxStartPoint;
        };
        counter counts{};
        counts.chatBoxStartPoint = CHATBOX_SIZE - lines;
        for (int i = 0; i < lines; i++) {
            // for each line
            for (int j = 0; j < lineArray[i].lineLength; j++) {
                // add message to new lines
                if (j == this->messageLength) {
                    break;
                }
                this->boxLines[counts.chatBoxStartPoint][j] = lineArray[i].line[j];
            }
            counts.chatBoxStartPoint++;
        }
    }
    // four line intake
    void enterMessage(string line1, string line2, string line3, string line4) {
        const int lines = 4;
        struct getLineArray {
            string line;
            int lineLength{};
        };
        struct getLineArray lineArray[lines];
        lineArray[0].line = line1;
        lineArray[0].lineLength = line1.length();
        lineArray[1].line = line2;
        lineArray[1].lineLength = line2.length();
        lineArray[2].line = line3;
        lineArray[2].lineLength = line3.length();
        lineArray[3].line = line4;
        lineArray[3].lineLength = line4.length();

        bumpMessage(lines); // push history chat up
        clearArray(lines); // clear off unwanted text on new lines
        struct counter {
            int chatBoxStartPoint;
        };
        counter counts{};
        counts.chatBoxStartPoint = CHATBOX_SIZE - lines;
        for (int i = 0; i < lines; i++) {
            // for each line
            for (int j = 0; j < lineArray[i].lineLength; j++) {
                // add message to new lines
                if (j == this->messageLength) {
                    break;
                }
                this->boxLines[counts.chatBoxStartPoint][j] = lineArray[i].line[j];
            }
            counts.chatBoxStartPoint++;
        }
    }
    // five line intake
    void enterMessage(string line1, string line2, string line3, string line4, string line5) {
        const int lines = 5;
        struct getLineArray {
            string line;
            int lineLength{};
        };
        struct getLineArray lineArray[lines];
        lineArray[0].line = line1;
        lineArray[0].lineLength = line1.length();
        lineArray[1].line = line2;
        lineArray[1].lineLength = line2.length();
        lineArray[2].line = line3;
        lineArray[2].lineLength = line3.length();
        lineArray[3].line = line4;
        lineArray[3].lineLength = line4.length();
        lineArray[4].line = line5;
        lineArray[4].lineLength = line5.length();

        bumpMessage(lines); // push history chat up
        clearArray(lines); // clear off unwanted text on new lines
        struct counter {
            int chatBoxStartPoint;
        };
        counter counts{};
        counts.chatBoxStartPoint = CHATBOX_SIZE - lines;
        for (int i = 0; i < lines; i++) {
            // for each line
            for (int j = 0; j < lineArray[i].lineLength; j++) {
                // add message to new lines
                if (j == this->messageLength) {
                    break;
                }
                this->boxLines[counts.chatBoxStartPoint][j] = lineArray[i].line[j];
            }
            counts.chatBoxStartPoint++;
        }
    }
    // six line intake (max)
    void enterMessage(string line1, string line2, string line3, string line4, string line5, string line6) {
        const int lines = 6;
        struct getLineArray {
            string line;
            int lineLength{};
        };
        struct getLineArray lineArray[lines];
        lineArray[0].line = line1;
        lineArray[0].lineLength = line1.length();
        lineArray[1].line = line2;
        lineArray[1].lineLength = line2.length();
        lineArray[2].line = line3;
        lineArray[2].lineLength = line3.length();
        lineArray[3].line = line4;
        lineArray[3].lineLength = line4.length();
        lineArray[4].line = line5;
        lineArray[4].lineLength = line5.length();
        lineArray[5].line = line6;
        lineArray[5].lineLength = line6.length();

        bumpMessage(lines); // push history chat up
        clearArray(lines); // clear off unwanted text on new lines
        struct counter {
            int chatBoxStartPoint;
        };
        counter counts{};
        counts.chatBoxStartPoint = CHATBOX_SIZE - lines;
        for (int i = 0; i < lines; i++) {
            // for each line
            for (int j = 0; j < lineArray[i].lineLength; j++) {
                // add message to new lines
                if (j == this->messageLength) {
                    break;
                }
                this->boxLines[counts.chatBoxStartPoint][j] = lineArray[i].line[j];
            }
            counts.chatBoxStartPoint++;
        }
    }

    void printChatBox() {
        printf("\n-------------------chat-box---------------------\n");  //49
        for (auto& i : this->boxLines) {
            printf("|");
            for (int j = 0; j < this->messageLength; j++) {
                printf("%c", i[j]);
            }
            printf("|\n");
        }
        printf("------------------------------------------------");
    }
};

void printScreen(Map map, ChatBox chatBox) {
    system("CLS");
    map.printMap();
    chatBox.printChatBox();
}

int main() {
    Map map;
    ChatBox chatBox;
    string instruction;
    string name;
    Player player;
    LockedDoor ld;
    UnlockedDoor ud;
    Table t;
    Chair c;
    Bed b;
    Plant p;
    Light l;

    cout << "Hi Adventurer, welcome to QuizLand!" << endl;
    cout << "But first, we would like to know your name: ";

    getline(cin, name);
    player.setName(name);
    player.printName();

    while (true) {
        map.setItem(0, 0, ld.printinfo(']'));
        //map.setItem(0, 0, ud.printinfo('['));
        map.setItem(7, 13, t.printinfo('T'));
        map.setItem(7, 12, c.printinfo('h'));
        map.setItem(5, 10, b.printinfo('='));
        map.setItem(7, 6, p.printinfo('+'));
        map.setItem(4, 11, l.printinfo('*'));

        player.printDirection();
        printScreen(map, chatBox);
        cout << "\nEnter next step: ";
        getline(cin, instruction);
        if (instruction == "i quit bitch") {
            break;
        }
        else {
            player.setDirection(instruction);
            player.printDirection();
            map.setItem(player.getX(), player.getY(), player.getPlayerIcon());
            chatBox.enterMessage(instruction);
            continue;
        }
    }
    return 0;
}
