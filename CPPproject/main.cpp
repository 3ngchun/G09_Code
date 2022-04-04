#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
#include "RoomItem.h"

using namespace std;

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
    map.setItem(player.getX(), player.getY(), player.getPlayerIcon());

    while (true) {
        map.setItem(0, 0, ld.printinfo());
        //map.setItem(0, 0, ud.printinfo());
        map.setItem(13, 7, t.printinfo());
        map.setItem(12, 7, c.printinfo());
        map.setItem(10, 5, b.printinfo());
        map.setItem(6, 7, p.printinfo());
        map.setItem(11, 4, l.printinfo());

        system("CLS");
        map.printMap();
        map.resetItem(player.getX(), player.getY());
        chatBox.printChatBox();
        cout << "\nEnter next step: ";
        getline(cin, instruction);
        if (instruction == "i quit bitch") {
            break;
        } else {
            player.setDirection(instruction);
            player.printDirection();
            map.setItem(player.getX(), player.getY(), player.getPlayerIcon());

            if(map.checkMap(player) == "out"){
                chatBox.enterMessage(map.isWhatItemAhead(player));
            } 
            else if (map.checkMap(player) == "Item") {
                chatBox.enterMessage(map.isWhatItemAhead(player));
            }
            else {
                chatBox.enterMessage(instruction);
            }
            continue;
        }
    }
    return 0;
}
