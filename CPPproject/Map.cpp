#include <cstring>
#include <string>
#include "Map.h"
#include "Player.h"
#include "RoomItem.h"

class ChatBox;

void Map::createMap() {

    for (auto &i: this->mapping) {
        for (char &j: i) {
            j = this->space;
        }
    }
}

Map::Map() {
    createMap();
}
string Map::isOutOfBound(Player player) {
    // check item ahead of player is out of bound or what item is it
    int x = player.getX();
    int y = player.getY();
    char face = player.getPlayerIcon();
    string next_facing_item;
    switch (face){
        case '^':
            if (y != 0) {
                next_facing_item = getItem(x, y - 1);
            } else {
                next_facing_item = "out";
            }
            break;
        case 'v':
            if (y != 15) {
                next_facing_item = getItem(x, y + 1);
            } else {
                next_facing_item = "out";
            }
            break;
        case '<':
            if (x != 0) {
                next_facing_item = getItem(x - 1, y);
            } else {
                next_facing_item = "out";
            }
            break;
        case '>':
            if (x != 15) {
                next_facing_item = getItem(x + 1, y);
            } else {
                next_facing_item = "out";
            }
            break;
        default:
            next_facing_item = this->space;
            break;
    }
    return next_facing_item;
}
string Map::checkMap(Player player) {
    // return item ahead of player
    int x = player.getX();
    int y = player.getY();
    char face = player.getPlayerIcon();
    string next_facing_item;
    switch (face){
        case '^':
            if (y != 0) {
                next_facing_item = getItem(x, y - 1);
                if (next_facing_item.compare(" ") != 0) {
                    next_facing_item = "Item";
                }
            } else {
                next_facing_item = "out";
            }
            break;
        case 'v':
            if (y != 15) {
                next_facing_item = getItem(x, y + 1);
                if (next_facing_item.compare(" ") != 0) {
                    next_facing_item = "Item";
                }
            } else {
                next_facing_item = "out";
            }
            break;
        case '<':
            if (x != 0) {
                next_facing_item = getItem(x - 1, y);
                if (next_facing_item.compare(" ") != 0) {
                    next_facing_item = "Item";
                }
            } else {
                next_facing_item = "out";
            }
            break;
        case '>':
            if (x != 15) {
                next_facing_item = getItem(x + 1, y);
                if (next_facing_item.compare(" ") != 0) {
                    next_facing_item = "Item";
                }
            } else {
                next_facing_item = "out";
            }
            break;
        default:
            next_facing_item = this->space;
            break;
    }
    return next_facing_item;
}

string Map::isWhatItemAhead(Player player) {
    // return item char ahead of player in string type
    int x = player.getX();
    int y = player.getY();
    char face = player.getPlayerIcon();
    string next_facing_item;
    switch (face){
        case '^':
            if (y != 0) {
                next_facing_item = getItem(x, y - 1);
            } else {
                next_facing_item = "above is outside of map";
            }
            break;
        case 'v':
            if (y != 15) {
                next_facing_item = getItem(x, y + 1);
            } else {
                next_facing_item = "below is outside of map";
            }
            break;
        case '<':
            if (x != 0) {
                next_facing_item = getItem(x - 1, y);
            } else {
                next_facing_item = "further left is outside of map";
            }
            break;
        case '>':
            if (x != 15) {
                next_facing_item = getItem(x + 1, y);
            } else {
                next_facing_item = "further right is outside of map";
            }
            break;
        default:
            next_facing_item = this->space;
            break;
    }
    return next_facing_item;
}

string Map::printItemAhead(string next_facing_item) {
    if (next_facing_item.compare("]") == 0) {
        next_facing_item = "Locked door ahead";
    }
    else if (next_facing_item.compare("[") == 0) {
        next_facing_item = "Unlocked door ahead";
    }
    else if (next_facing_item.compare("h") == 0) {
        next_facing_item = "There is a chair ahead";
    }
    else if (next_facing_item.compare("T") == 0) {
        next_facing_item = "There is a table ahead";
    }
    else if (next_facing_item.compare("=") == 0) {
        next_facing_item = "There is a bed ahead";
    }
    else if (next_facing_item.compare("+") == 0) {
        next_facing_item = "There is a plant ahead";
    }
    else if (next_facing_item.compare("*") == 0) {
        next_facing_item = "There is a lamp ahead";
    }
    return next_facing_item;
}

void Map::printMap() {
    for (auto &i : mapping) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (j % 16 == 0) {
                SetConsoleTextAttribute(hConsole, 7);
                printf("\n");
            }
            if (i[j] == '^' || i[j] == 'v' || i[j] == '<' || i[j] == '>') {
                printf("[");
                SetConsoleTextAttribute(hConsole, 10);
                printf("%c", i[j]);
                SetConsoleTextAttribute(hConsole, 7);
                printf("]");
            }
            else {
                SetConsoleTextAttribute(hConsole, 7);
                printf("[%c]", i[j]);

            }
        }
    }
}

void Map::setItem(int x, int y, char item) {
    // set x,y position to item char
    this->mapping[y][x] = item;
}

void Map::resetItem(int x, int y) {
    // reset x,y position back to space
    this->mapping[y][x] = this->space;
}

char Map::getItem(int x, int y){
    return this->mapping[y][x];
}
void ChatBox::createChatBox() {
    // initialise chatBox
    for (auto &i: this->boxLines) {
        for (int j = 0; j < this->messageLength; j++) {
            i[j] = this->space;
        }
    }
    system("CLS");
}

void ChatBox::bumpMessage(int lines) {
    for (int i = 0; i < CHATBOX_SIZE - lines; i++) {
        // move all message up
        copy(begin(this->boxLines[i + lines]), end(this->boxLines[i + lines]), begin(this->boxLines[i]));
    }
}

void ChatBox::clearArray(int lines) {
    for (int i = 1; i < lines + 1; i++) {
        // clear array for new lines
        fill_n(this->boxLines[CHATBOX_SIZE - i], this->messageLength, this->space);  // clear last line
    }
}

ChatBox::ChatBox() {
    createChatBox();
}

void ChatBox::printChatBox() {
    printf("\n-------------------chat-box---------------------\n");  //49
    for (auto &i: this->boxLines) {
        printf("|");
        for (int j = 0; j < this->messageLength; j++) {
            printf("%c", i[j]);
        }
        printf("|\n");
    }
    printf("------------------------------------------------");
}

// one line intake
void ChatBox::enterMessage(string line1) {
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
void ChatBox::enterMessage(string line1, string line2) {
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
void ChatBox::enterMessage(string line1, string line2, string line3) {
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
void ChatBox::enterMessage(string line1, string line2, string line3, string line4) {
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
void ChatBox::enterMessage(string line1, string line2, string line3, string line4, string line5) {
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
void ChatBox::enterMessage(string line1, string line2, string line3, string line4, string line5, string line6) {
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




