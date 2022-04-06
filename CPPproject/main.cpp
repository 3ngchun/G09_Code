#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
#include "RoomItem.h"
#include "Puzzles.h"

using namespace std;

int main() {

    Map map;
    ChatBox cb;
    ChatBox* chatBox = &cb;
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
    Puzzle* puzzles[20];
    initPuzzles(puzzles);

    cout << "Hi Adventurer, welcome to QuizLand!" << endl;
    do {
        try {
            cin >> player;
        }
        catch (const string msg) {
            cout << msg << endl;
            player.setName(" ");
        }
        catch (const int length) {
            cout << "Name should not exceed 15 characters" << endl;
            player.setName(" ");
        }
    } while (player.getName() == " ");

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
        chatBox->printChatBox();
        cout << "\nEnter next step: ";
        getline(cin, instruction);
        if (instruction == "i quit bitch") {
            break;
        } else {
            player.setDirection(instruction);
            player.printDirection();
            map.setItem(player.getX(), player.getY(), player.getPlayerIcon());

            if(map.checkMap(player) == "out"){
                chatBox->enterMessage(map.isWhatItemAhead(player));
            } 
            else if (map.checkMap(player) == "Item") {
                string item = map.isWhatItemAhead(player);
                chatBox->enterMessage(map.printItemAhead(item));
                chatBox->enterMessage("Enter 'interact' to interact with item");
                chatBox->enterMessage(instruction);
                if (instruction == "interact") {
                    //TODO Add Puzzle hanlder
                    // randomPuzzle(puzzles, chatBox);
                    puzzles[1]->startPuzzle(chatBox, map);
                    // puzzles[0]->startPuzzle(chatBox);
                }
            }
            else {
                chatBox->enterMessage(instruction);
            }
            continue;
        }
    }
    return 0;
}
