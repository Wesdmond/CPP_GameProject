#include "events.h"
#include "printer.h"
#include "class.h"
#include <iostream>
#include <vector>
void ItsATrap(int& PlayerHP)
{   
	int start = 5;
	int end = 10;
	int damage = rand() % (end - start + 1) + start;
	PlayerHP -= damage;
	std::cout << printColored("It's a trap!!!", Color::RED) << " You've been damaged " << damage << std::endl;
	if (PlayerHP <= 0)
	{
		std::cout << printColored("You failed\n", Color::RED);
	}
}

void Gift()
{
	int start = 1;
	int end = 3;
	int gift = rand() % (end - start + 1) + start;
	Weapon WeaponGift = Vw[gift];
	std::cout << "You found " << printColored(WeaponGift.name, Color::YELLOW) << "!\n";
	bool found1 = false;
	for (auto& invent : inventory) {
		if (WeaponGift.id == invent.first.id) {
			invent.second++;
			found1 = true;
			break;
		}
	}
	if (!found1) {
		inventory.emplace_back(WeaponGift, 1);
	}
	bool know = 0;
	for (auto& recipe : KnownRecipes) {

		if (WeaponGift.id == recipe.id) {
			know = 1;
		}
	}
	if (know == 0)
	{
		KnownRecipes.push_back(WeaponGift);
	}
	int j = 1;
	for (const auto& weapon : inventory) {
		std::cout << printColored(std::to_string(j), Color::YELLOW) << ") " << weapon.first.name
			<< ", DMG: " << weapon.first.DMG << ", Souls: " << weapon.first.Souls << ", Silvers: " << weapon.first.Silvers
			<< ", Solar Fragments: " << weapon.first.Solar_Fragments << "\tx" << weapon.second << std::endl;
		j++;
	}
}