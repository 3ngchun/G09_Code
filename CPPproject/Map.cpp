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
    switch (face) {
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
    switch (face) {
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
    switch (face) {
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

void Map::fillRoomItem(struct createRoomItemArray *roomItemArray) {
    // fill struct array with room items and set them onto map
    LockedDoor ld;
    UnlockedDoor ud;
    Table t;
    Chair c;
    Bed b;
    Plant p;
    Light l;
    roomItemArray[0].x = ld.getX();
    roomItemArray[0].y = ld.getY();
    roomItemArray[0].item = ld.printinfo();
    roomItemArray[1].x = t.getX();
    roomItemArray[1].y = t.getY();
    roomItemArray[1].item = t.printinfo();
    roomItemArray[2].x = c.getX();
    roomItemArray[2].y = c.getY();
    roomItemArray[2].item = c.printinfo();
    roomItemArray[3].x = b.getX();
    roomItemArray[3].y = b.getY();
    roomItemArray[3].item = b.printinfo();
    roomItemArray[4].x = p.getX();
    roomItemArray[4].y = p.getY();
    roomItemArray[4].item = b.printinfo();
    roomItemArray[5].x = l.getX();
    roomItemArray[5].y = l.getY();
    roomItemArray[5].item = l.printinfo();
    for (int i = 0; i < 6; i++) {
        setItem(roomItemArray[i].x, roomItemArray[i].y, roomItemArray[i].item);
    }
}

string Map::printItemAhead(string next_facing_item) {
    // return string of room item ahead of player
    if (next_facing_item.compare("]") == 0) {
        next_facing_item = "Locked door ahead";
    } else if (next_facing_item.compare("[") == 0) {
        next_facing_item = "Unlocked door ahead";
    } else if (next_facing_item.compare("h") == 0) {
        next_facing_item = "There is a chair ahead";
    } else if (next_facing_item.compare("T") == 0) {
        next_facing_item = "There is a table ahead";
    } else if (next_facing_item.compare("=") == 0) {
        next_facing_item = "There is a bed ahead";
    } else if (next_facing_item.compare("+") == 0) {
        next_facing_item = "There is a plant ahead";
    } else if (next_facing_item.compare("*") == 0) {
        next_facing_item = "There is a lamp ahead";
    }
    return next_facing_item;
}

void Map::printMap() {
    // print map background
    for (auto &i: mapping) {
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
            } else {
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

char Map::getItem(int x, int y) {
    // return item on xy pos
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
    // update chatbox
    for (int i = 0; i < CHATBOX_SIZE - lines; i++) {
        // move all message up
        copy(begin(this->boxLines[i + lines]), end(this->boxLines[i + lines]), begin(this->boxLines[i]));
    }
}

void ChatBox::clearArray(int lines) {
    // clear array for new lines
    for (int i = 1; i < lines + 1; i++) {
        fill_n(this->boxLines[CHATBOX_SIZE - i], this->messageLength, this->space);  // clear last line
    }
}

ChatBox::ChatBox() {
    createChatBox();
}

void ChatBox::printChatBox() {
    // print chatbox background
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

void ChatBox::enterMessage(string line1) {
    // one line intake
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

void ChatBox::enterMessage(string line1, string line2) {
    // two line intake
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

void ChatBox::enterMessage(string line1, string line2, string line3) {
    // three line intake
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

void ChatBox::enterMessage(string line1, string line2, string line3, string line4) {
    // four line intake
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

void ChatBox::enterMessage(string line1, string line2, string line3, string line4, string line5) {
    // five line intake
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

void ChatBox::enterMessage(string line1, string line2, string line3, string line4, string line5, string line6) {
    // six line intake (max)
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




