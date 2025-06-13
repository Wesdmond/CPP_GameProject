#include "menu.h"
#include "printer.h"
#include <iostream>
void showMenu() {
	std::cout << "\nWhat to do? Enter number\n\t" <<
		printColored("1", Color::YELLOW) << ") Check the chest near the dungeon\n\t" <<
		printColored("2", Color::YELLOW) << ") Craft\n\t" <<
		printColored("3", Color::YELLOW) << ") Go to dungeon\n\t" <<
		printColored("4", Color::YELLOW) << ") Change weapon\n\t" <<
		printColored("5", Color::YELLOW) << ") Load last game\n\t" <<
		printColored("0", Color::YELLOW) << ") Exit game" << std::endl;
}