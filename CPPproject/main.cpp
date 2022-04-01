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

    while (true) {
        map.setItem(0, 0, ld.printinfo());
        //map.setItem(0, 0, ud.printinfo());
        map.setItem(7, 13, t.printinfo());
        map.setItem(7, 12, c.printinfo());
        map.setItem(5, 10, b.printinfo());
        map.setItem(7, 6, p.printinfo());
        map.setItem(4, 11, l.printinfo());

        system("CLS");
        map.printMap();
        chatBox.printChatBox();
        cout << "\nEnter next step: ";
        getline(cin, instruction);
        if (instruction == "i quit bitch") {
            break;
        } else {
            player.setDirection(instruction);
            player.printDirection();
            map.setItem(player.getX(), player.getY(), player.getPlayerIcon());
            chatBox.enterMessage(instruction);
            continue;
        }
    }
    return 0;
}
