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
        map.setItem(ld.getX(), ld.getY(), ld.printinfo());
        //map.setItem(0, 0, ud.printinfo());
        map.setItem(t.getX(), t.getY(), t.printinfo());
        map.setItem(c.getX(), c.getY(), c.printinfo());
        map.setItem(b.getX(), b.getY(), b.printinfo());
        map.setItem(p.getX(), p.getY(), p.printinfo());
        map.setItem(l.getX(), l.getY(), l.printinfo());

        system("CLS");
        player.printName();
        cout << "\nUser Instruction Guide:";
        cout << "\nDirection: up / down / left / right";
        cout << "\nGive up: quit";
        cout << "\nInteract with all room items to solve puzzles and escape the room!\n";
        map.printMap();
        map.resetItem(player.getX(), player.getY());
        chatBox->printChatBox();
        cout << "\nEnter next step: ";
        getline(cin, instruction);
        if (instruction == "quit") {
            break;
        }
        else {
            player.setDirection(instruction);
            player.printDirection();
            map.setItem(player.getX(), player.getY(), player.getPlayerIcon());

            if (map.checkMap(player) == "out") {
                chatBox->enterMessage(map.isWhatItemAhead(player));
            }
            else if (map.checkMap(player) == "Item") {
                string item = map.isWhatItemAhead(player);
                chatBox->enterMessage(map.printItemAhead(item));
                chatBox->enterMessage("Enter 'interact' to interact with item");
                chatBox->enterMessage(instruction);
                if (instruction == "interact") {
                    if (item == "]") { //check if player at door
                        if (unlockDoorCheck(puzzles) != 1) { //check if all puzzles solved
                            chatBox->enterMessage("", "Door is locked :(");
                        }
                        else { //else print locked
                            chatBox->enterMessage("", "Hoorah! Door is unlocked!!!!");
                            chatBox->enterMessage("", "Enter 'win' to complete the game");
                        }
                    }
                    else { // If not door, run puzzle
                        randomPuzzle(puzzles, chatBox, map);
                    }
                }
                else if ((item == "]") && (instruction == "win") && (unlockDoorCheck(puzzles) == 1)) {
                    break;
                }
            }
            else {
                chatBox->enterMessage(instruction);
            }
            continue;
        }
    }
    // win sequence
    system("CLS");
    std::cout << R"(
                        __  ______  __  __   _       _______   ______                          
                        \ \/ / __ \/ / / /  | |     / /  _/ | / / / /                          
                         \  / / / / / / /   | | /| / // //  |/ / / /                           
                         / / /_/ / /_/ /    | |/ |/ // // /|  /_/_/                            
                        /_/\____/\____/     |__/|__/___/_/ |_(_|_)                             
                                                                                               
  ________                __           ____              ____  __            _             ____
 /_  __/ /_  ____ _____  / /_______   / __/___  _____   / __ \/ /___ ___  __(_)___  ____ _/ / /
  / / / __ \/ __ `/ __ \/ //_/ ___/  / /_/ __ \/ ___/  / /_/ / / __ `/ / / / / __ \/ __ `/ / / 
 / / / / / / /_/ / / / / ,< (__  )  / __/ /_/ / /     / ____/ / /_/ / /_/ / / / / / /_/ /_/_/  
/_/ /_/ /_/\__,_/_/ /_/_/|_/____/  /_/  \____/_/     /_/   /_/\__,_/\__, /_/_/ /_/\__, (_|_)   
                                                                   /____/        /____/        
)" << '\n';


    return 0;
}
