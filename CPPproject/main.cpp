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

    map.setItem(player.getX(), player.getY(), player.getPlayerIcon());

    while (true) { 
        map.setItem(ld.getX(),ld.getY(), ld.printinfo());
        //map.setItem(0, 0, ud.printinfo());
        map.setItem(t.getX(), t.getY(), t.printinfo());
        map.setItem(c.getX(), c.getY(), c.printinfo());
        map.setItem(b.getX(), b.getY(), b.printinfo());
        map.setItem(p.getX(), p.getY(), p.printinfo());
        map.setItem(l.getX(), l.getY(), l.printinfo());

        system("CLS");
        player.printName();
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
