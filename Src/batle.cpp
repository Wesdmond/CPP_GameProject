#include "batle.h"
#include "class.h"
#include "readtext.h"
#include "printer.h"
#include <iostream>

bool batle(int enemy, int &PlayerHP, int PlayerDMG) {
	int MonsterHP = Vc[enemy].MAX_HP;
	bool turn = 1;
	std::cout << "Battle started, your enemy is " << printColored(Vc[enemy].name, Color::YELLOW)
		<< " his health is " << printColored(std::to_string(Vc[enemy].MAX_HP), Color::GREEN) << std::endl;
	while (PlayerHP > 0 && MonsterHP > 0)
	{   
		if (turn == 1)
		{
			char choice;
			std::cout << "What to do?\n\t" << 
				printColored("1", Color::YELLOW) << ") Attack\n\t" <<
				printColored("2", Color::YELLOW) << ") Escape\n";
			std::cin >> choice;
			switch (choice)

			{
			case '1':
				MonsterHP -= PlayerDMG;
				if (MonsterHP < 0) MonsterHP = 0;
				std::cout << printColored("You", Color::YELLOW) << " dealt " << 
					printColored(std::to_string(PlayerDMG), Color::RED) << " damage\t" << 
					printColored(Vc[enemy].name + "'s", Color::YELLOW) << " HP is " << 
					printColored(std::to_string(MonsterHP), Color::GREEN) << std::endl;
				if (MonsterHP <= 0 && Vc[enemy].id != (Vc.size() - 1))
					return 1;
				if (MonsterHP <= 0 && Vc[enemy].id == (Vc.size() - 1))
				{
					Display("Data/win.txt"); 
					exit(0);
				}
				turn = 0;
				break;
			case '2':
				return 0;
				break;
			default:
				std::cout << printColored("Error:", Color::RED) << " try again\n";
				break;
			}
		}
		if (turn == 0) 
		{
			PlayerHP -=Vc[enemy].DMG;

			std::cout << printColored("Your", Color::YELLOW) << " HP is " <<
				printColored(std::to_string(PlayerHP), Color::GREEN) << " after \t" <<
				printColored(Vc[enemy].name, Color::YELLOW) << " dealt " <<
				printColored(std::to_string(Vc[enemy].DMG), Color::RED) << " damage" << std::endl;
			if (PlayerHP <= 0)
				return 0;
			turn = 1;
		}
	}
}