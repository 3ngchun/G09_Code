#include <iostream>
#include <string>
#include "Player.h"
#include "Map.h"
#include "RoomItem.h"
#include "Puzzles.h"

using namespace std;

void printScreen(Map map, ChatBox chatBox) {
    // friend function to print game background as a set
    map.printMap();
    chatBox.printChatBox();
}

int main() {
    // initialise objects
    Map map;
    ChatBox cb;
    ChatBox *chatBox = &cb;
    string instruction;
    string name;
    Player player;
    UnlockedDoor ud;
    Puzzle *puzzles[5];
    initPuzzles(puzzles);

    cout << "Hi Adventurer, welcome to QuizLand!" << endl;
    do {
        // welcome message and get player name
        try {
            cin >> player;
        }
        catch (const invalid_argument &e) {
            // if player enter special character
            cout << e.what() << endl;
            player.setName(" ");
        }
        catch (const length_error &e) {
            // if player enter more than 15 character
            cout << e.what() << endl;
            player.setName(" ");
        }
    } while (player.getName() == " ");
    // prepare room item
    map.setItem(player.getX(), player.getY(), player.getPlayerIcon());
    createRoomItemArray roomItemArray[6];
    map.fillRoomItem(roomItemArray);
    chatBox->enterMessage(player.printName());
    chatBox->enterMessage("Are you ready to start your adventure?");
    while (true) {
        // game loop
        system("CLS"); // refresh screen
        player.printName();
        Player::userGuide();
        printScreen(map, *chatBox);  // game background
        map.resetItem(player.getX(), player.getY()); // remove player trace
        cout << "\nEnter next step: ";
        getline(cin, instruction);
        if (instruction == "quit") {
            // if quit, stop loop
            break;
        } else {
            player.setDirection(instruction); // if player move, set change player icon direction
            player.printDirection(roomItemArray);
            map.setItem(player.getX(), player.getY(), player.getPlayerIcon()); // set player onto map
            if (map.checkMap(player) == "out") {
                // if out of boundary, print direction to out of bound
                chatBox->enterMessage(map.isWhatItemAhead(player));
            } else if (map.checkMap(player) == "Item") {
                string item = map.isWhatItemAhead(player);
                chatBox->enterMessage(Map::printItemAhead(item));
                chatBox->enterMessage("Enter 'interact' to interact with item");
                chatBox->enterMessage(instruction);
                if (instruction == "interact") {
                    if (item == "]") { //check if player at door
                        if (unlockDoorCheck(puzzles) != 1) { //check if all puzzles solved
                            chatBox->enterMessage("", "Door is locked :(");
                        } else { //else print unlocked
                            map.setItem(0, 0, ud.printinfo());
                            chatBox->enterMessage("", "Hoorah! Door is unlocked!!!!");
                            chatBox->enterMessage("", "Enter 'win' to complete the game");
                        }
                    } else { // If not door, run puzzle
                        int beforePuzzles;
                        int afterPuzzles;
                        beforePuzzles = numPuzzleSolved(puzzles); //checks for the number of solved puzzles before
                        randomPuzzle(puzzles, chatBox, map); // call randomPuzzle method
                        afterPuzzles = numPuzzleSolved(
                                puzzles); //checks for no of puzzles solved after player interaction
                        if (afterPuzzles > beforePuzzles) { // if after more than before means player solved puzzle
                            string isWhatItemAhead = map.isWhatItemAhead(player); //get item that was interacted with
                            for (auto &roomItemArrayTmp: roomItemArray) {
                                if (roomItemArrayTmp.item == isWhatItemAhead[0]) { //traverse and look for matching item
                                    map.resetItem(roomItemArrayTmp.x,
                                                  roomItemArrayTmp.y); //reset item (remove from map)
                                    roomItemArrayTmp.item = '0';
                                    roomItemArrayTmp.x = -1;
                                    roomItemArrayTmp.y = -1;
                                    break;
                                }
                            }
                        }

                    }
                } else if ((item == "[") && (instruction == "win") && (unlockDoorCheck(puzzles) == 1)) {
                    break;
                }
            } else {
                chatBox->enterMessage(instruction);
            }
            continue;
        }
    }
    // win and exit sequence
    system("CLS");
    if (instruction == "win") {
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
    } else {
        std::cout << R"(
                                                             _       __
   ________  ___     __  ______  __  __   ____ _____ _____ _(_)___  / /
  / ___/ _ \/ _ \   / / / / __ \/ / / /  / __ `/ __ `/ __ `/ / __ \/ / 
 (__  )  __/  __/  / /_/ / /_/ / /_/ /  / /_/ / /_/ / /_/ / / / / /_/  
/____/\___/\___/   \__, /\____/\__,_/   \__,_/\__, /\__,_/_/_/ /_(_)   
                  /____/                     /____/                    

)" << '\n';
    }
    return 0;
}
