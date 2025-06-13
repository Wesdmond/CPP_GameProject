#include "dungeon.h"
#include "class.h"
#include "batle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "events.h"
#include "printer.h"
#include "save_system.h"

int ChanceOfRoomToHasEvent = 35; // from 0 to 100


void GoToDange() {
	std::vector<std::vector<int>> BatleArray = array;
#ifdef NDEBUG
	Ve.clear();
	for (int i = 0; i < array.size(); i++)
		for (int j = 0; j < array[0].size(); j++)
		{
			int random_num = (std::rand() % (100 + 1));
			if (random_num <= ChanceOfRoomToHasEvent)
				Ve.push_back(std::make_pair(i, j));
		}
#endif
	std::pair<int, int> start = std::make_pair(4, 2);
	std::pair<int, int> CurrentRoom = start;
	bool GoAway = 0;
	char choice;
	std::vector<int> DangeResources = {0, 0, 0};
	int hp = Vc[0].MAX_HP;
	while (GoAway == 0) {
		int element = BatleArray[CurrentRoom.first][CurrentRoom.second];
		if (element != 0) {
			bool result = batle(element,hp,Vc[0].DMG);
			if (result == 0) {
				std::cout << printColored("You failed\n", Color::RED);
				GoAway = 1;
				break;
			}
			if (result == 1) {
				std::cout << "You win the battle\n";
				DangeResources[0] += Vc[element].Souls;
				DangeResources[1] += Vc[element].Silvers;
				DangeResources[2] += Vc[element].Solar_Fragments;
				BatleArray[CurrentRoom.first][CurrentRoom.second] = 0;
				for (const auto& room : Ve)
				{
					if (CurrentRoom == room)
					{
						int start = 1;
						int end = 10;
						int x = rand() % (end - start + 1) + start;
						bool ansver = 0;
						while (ansver == 0) {
							std::cout << "Seems there's something here\nWhat to do?\n\t" <<
								printColored("1", Color::YELLOW) << ") Look\n\t" <<
								printColored("2", Color::YELLOW) << ") Ignore\n";
							char choice;
							std::cin >> choice;
							switch (choice) {
							case '1':
								ansver = 1;
								if (x <= 3)
								{
									ItsATrap(hp);
									if (hp <= 0) {
										break;
									}
								}
								if (x > 3)
								{
									Gift();
								}
								break;
							case '2':
								ansver = 1;
								break;
							default:
								std::cout << printColored("Error:", Color::RED) << " Try again" << std::endl;
								break;
							}
						}
					}
				}
			}
		}
		if (hp > 0) {
			if (element == 0)
				std::cout << "There are no enemies here\n";
			for (int i = 0; i < BatleArray.size(); ++i) {
				for (int j = 0; j < BatleArray[i].size(); ++j) {
					std::cout << "[";
					if (i == CurrentRoom.first && j== CurrentRoom.second)
						std::cout << printColored("O", Color::YELLOW);
					else if (BatleArray[i][j] == 0)
						std::cout << printColored("X", Color::BLUE);
					else std::cout << " ";
					std::cout << "]";
				}
				std::cout << std::endl;
			}

			std::cout << "Where to go?\n";
			if (CurrentRoom.second != 0)
				std::cout << "\tGo left (" << printColored("L", Color::YELLOW) << ")\n";
			if (CurrentRoom.second != (BatleArray.size() - 1))
				std::cout << "\tGo right (" << printColored("R", Color::YELLOW) << ")\n";
			if (CurrentRoom.first != 0)
				std::cout << "\tGo up (" << printColored("U", Color::YELLOW) << ")\n";
			if (CurrentRoom.first != (BatleArray[CurrentRoom.first].size() - 1))
				std::cout << "\tGo down (" << printColored("D", Color::YELLOW) << ")\n";
			std::cout << "\tEnter " << printColored("0", Color::YELLOW) << " to exit\n";
			std::cin >> choice;
			if ((choice == 'L' || choice == 'l') && CurrentRoom.second != 0)
				CurrentRoom.second--;
			else if ((choice == 'R' || choice == 'r') && CurrentRoom.second != (BatleArray.size() - 1))
				CurrentRoom.second++;
			else if ((choice == 'U' || choice == 'u') && CurrentRoom.first != 0)
				CurrentRoom.first--;
			else if ((choice == 'D' || choice == 'd') && CurrentRoom.first != (BatleArray.size() - 1))
				CurrentRoom.first++;
			else if (choice == '0')
			{
				std::cout << "You got:\n";
				for (int i = 0; i < Resources.size(); i++) {
					std::cout << ResoursesNames[i] << ": " << printColored(DangeResources[i], Color::BLUE) << "   ";
					Resources[i] += DangeResources[i];
				}
				std::cout << std::endl;
				GoAway = 1;
				save_game();
			}
			else std::cout << "I can't go there!\n";
		}
	}
}
