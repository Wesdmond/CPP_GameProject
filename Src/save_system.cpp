#include "save_system.h"
#include "printer.h"
#include "class.h"
#include "fstream"
#include "iostream"

const std::string basic_filepath = "Data/save.txt";

void save_game()
{
	save_game(basic_filepath);
}

void save_game(const std::string& filename)
{
	std::cout << "Saving game..." << std::endl;
	std::ofstream out(filename);
	if (!out.is_open())
	{
		std::cout << printColored("Error:", Color::RED) << " can't open filepath: " << filename << std::endl;
		return;
	}
	out << "IS A NEW GAME:" << std::endl;
	out << is_new_game << std::endl;

	out << "INVENTORY:" << std::endl;
	out << inventory.size() << std::endl;
	for (const auto& item : inventory)
		out << item.first.to_string() << ' ' << item.second << std::endl;

	out << "RESOURCES:" << std::endl;
	out << Resources.size() << std::endl;
	for (int i = 0; i < Resources.size(); i++)
		out << Resources[i] << ' ';

	out.close();
	std::cout << "Saving is succesful!" << std::endl;
}

void load_game()
{
	load_game(basic_filepath);
}

void load_game(const std::string& filename)
{
	std::cout << "Loading save..." << std::endl;
	std::ifstream in(filename);
	if (!in.is_open())
	{
		std::cout << printColored("Error:", Color::RED) << " can't open filepath: " << filename << std::endl;
		return;
	}
	try
	{
		std::string temp;
		std::getline(in, temp); // Пропуск текстового поля
		int itemp;
		in >> itemp;
		std::cout << itemp << std::endl;
		is_new_game = itemp;
		std::cout << is_new_game << std::endl;

		std::getline(in, temp); // Пропуск текстового поля
		int count = 0;
		in >> count;
		inventory.clear();
		for (int i = 0; i < count; i++)
		{
			int id;
			std::string name;
			int dmg;
			std::vector<std::pair <int, int>>craftR; int cnt;
			int souls, silvers, solar_Fragments;

			int first, second;
			in >> id >> name >> dmg >> cnt;
			for (int i = 0; i < cnt; i++)
			{
				in >> first >> second;
				craftR.emplace_back(first, second);
			}
			in >> souls >> silvers >> solar_Fragments >> cnt;


			inventory.emplace_back(Weapon(id, name, dmg, std::move(craftR), souls, silvers, solar_Fragments), cnt);
		}

		std::getline(in, temp); // Пропуск текстового поля
		Resources.clear();
		in >> count;
		for (int i = 0; i < count; i++)
		{
			int tempi = 0;
			in >> tempi;
			Resources.push_back(tempi);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << printColored("Error:", Color::RED) << " Failed to load file: " << e.what() << std::endl;
		inventory.clear();
		Resources = { 0, 0, 0 };
		is_new_game = true;
	}
	std::cout << "Inventory size: = " << inventory.size() << " (FROM Loading File)" << std::endl;
	std::cout << "Loading is succesful!" << std::endl;
	in.close();
}