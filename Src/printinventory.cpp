#include "printinventory.h"
#include "printer.h"
#include "class.h"
#include <iostream>

void PrintInventory()
{
    if (inventory.size() == 0)
    {
        std::cout << "There are no weapons in inventory." << std::endl;
        return;
    }
    int j = 1;
    for (const auto& weapon : inventory) {
        std::cout << printColored(j, Color::YELLOW) << ") " << weapon.first.name
            << ", DMG: " << printColored(weapon.first.DMG, Color::YELLOW) << ", Souls: " <<
            printColored(weapon.first.Souls, Color::BLUE) << ", Silvers: " <<
            printColored(weapon.first.Silvers, Color::BLUE) << ", Solar Fragments: " <<
            printColored(weapon.first.Solar_Fragments, Color::BLUE) << "\tx" << printColored(weapon.second, Color::GREEN) << std::endl;
        j++;
    }
}

void PrintKnownRec()
{
    int k = 1;
    for (const auto& weapon : KnownRecipes) {
        std::cout << printColored(k, Color::YELLOW) << ") " << weapon.name
            << ", DMG: " << printColored(weapon.DMG, Color::YELLOW) << ", Souls: " <<
            printColored(weapon.Souls, Color::BLUE) << ", Silvers: " <<
            printColored(weapon.Silvers, Color::BLUE) << ", Solar Fragments: " <<
            printColored(weapon.Solar_Fragments, Color::BLUE) << std::endl;
        k++;
    }
}