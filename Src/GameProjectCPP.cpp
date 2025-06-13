#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "class.h"
#include "read.h"
#include "menu.h"
#include "craft.h"
#include "dungeon.h"
#include "printinventory.h"
#include "printer.h"
#include "readtext.h"
#include "save_system.h"

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    ReadFromFile();
    Display("Data/start.txt");
    bool exit = 0;
    //load_game(); // TODO: Fix Save System
    Weapon WeaponEquiped = Vw[0];
    Vc[0].DMG = WeaponEquiped.DMG;
    while (exit == 0) {
        showMenu();
        char choice;
        std::cin >> choice;
        switch (choice) {
        case '1':
            Display("Data/Text1.txt");
            if (is_new_game)
            {
                std::cout << "Now you have some resources" << std::endl;
                for (int i = 0; i < Resources.size(); i++) {
                    Resources[i] += 5;
                    std::cout << ResoursesNames[i] << ": " << printColored(Resources[i], Color::BLUE) << "\t";
                }
                std::cout << std::endl;
                std::cout << "Now you have a " << printColored("STICK", Color::YELLOW) << '!' << std::endl;
                KnownRecipes.push_back(Vw[1]);
                inventory.emplace_back(Vw[1], 1);
                is_new_game = false;
            }
            else
            {
                std::cout << "This chest is empty" << std::endl;
            }
            break;

        case '2':
            Craft();
            break;

        case '3':
            GoToDange();
            break;

        case '4':
            PrintInventory();
            if (inventory.size() == 0) break;
            int choice2;
            std::cin >> choice2;
            if (choice2 > 0 && choice2 <= inventory.size()) {
                bool found1 = false;
                for (auto& invent : inventory) {
                    if (WeaponEquiped.id == invent.first.id) {
                        invent.second++;
                        found1 = true;
                        break;
                    }
                }
                if (!found1) {
                    inventory.emplace_back(WeaponEquiped, 1);
                }
                WeaponEquiped = Vw[inventory[choice2 - 1].first.id];
                Vc[0].DMG = WeaponEquiped.DMG;
                inventory[choice2 - 1].second--;
                // Проверяем, если количество предмета стало 0
                if (inventory[choice2 - 1].second == 0) {
                    inventory.erase(inventory.begin() + (choice2 - 1));
                }
                std::cout << "You're equiped "<< WeaponEquiped.name << " Now your damage is " << printColored(WeaponEquiped.DMG, Color::RED) << std::endl;
            }
            else {
                std::cout << printColored("Error:", Color::RED) << " Try again" << std::endl;
                break;
            }
            break; 

        case '5':
            load_game();
            //std::cout << "Is new game = " << is_new_game << std::endl;
            std::cout << "Inventory size: = " << inventory.size() << " (FROM Main File)" << std::endl;
            break;
        case '0':
            save_game();
            std::cout << "Exit" << std::endl;
            exit = 1;
            break;

        default:
            std::cout << printColored("Error:", Color::RED) << " Try again" << std::endl;
            break;
        }
    }
    return 0;
}