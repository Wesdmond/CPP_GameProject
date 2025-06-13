#include "craft.h"
#include "class.h"
#include "printinventory.h"
#include "printer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
std::vector<std::pair<Weapon, int>> inventory;
std::vector<Weapon> KnownRecipes;
std::vector<int> Resources = { 0, 0, 0 };
void Craft()
{
    bool exit = 0;
    while (exit == 0)
    {
        std::cout << "What do you want to do?\n\t" <<
            printColored("1", Color::YELLOW) << ") Copy weapon\n\t" <<
            printColored("2", Color::YELLOW) << ") Combine two weapon\n\t" << 
            printColored("0", Color::YELLOW) << ") Back to main menu" << std::endl;
        int i = 1;
        char choice;
        std::cin >> choice;
        switch (choice)
        {
        case '1':
            for (const auto& weapon : KnownRecipes)
            {
                std::cout << printColored(i, Color::YELLOW) << ") " << weapon.name
                    << ", DMG: " << printColored(weapon.DMG, Color::YELLOW) << ", Souls: " << 
                    printColored(weapon.Souls, Color::BLUE) << ", Silvers: " << 
                    printColored(weapon.Silvers, Color::BLUE) << ", Solar Fragments: " << 
                    printColored(weapon.Solar_Fragments, Color::BLUE) << std::endl;
                i++;
            }

            std::cout << "Your resourses:\n";
            for (int i = 0; i < Resources.size(); i++)
            {
                std::cout << ResoursesNames[i] << ": " << printColored(Resources[i], Color::BLUE) << "   ";
            }
            std::cout << "\nWhat do you want to copy/craft?\nEnter 0 to exit" << std::endl;
            int choiceC;
            std::cin >> choiceC;
            if (choiceC > 0 && choiceC <= KnownRecipes.size())
            {
                Weapon weaponCraft = KnownRecipes[choiceC - 1];
                if (weaponCraft.Souls <= Resources[0] && weaponCraft.Silvers <= Resources[1] && weaponCraft.Souls <= Resources[2])
                {
                    Resources[0] = Resources[0] - weaponCraft.Souls;
                    Resources[1] = Resources[1] - weaponCraft.Silvers;
                    Resources[2] = Resources[2] - weaponCraft.Solar_Fragments;
                    bool found = false;
                    for (auto& invent : inventory)
                    {
                        if (weaponCraft.id == invent.first.id)
                        {
                            invent.second++;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        inventory.emplace_back(weaponCraft, 1); // Если не нашли предмет, добавляем его
                    }
                    std::cout << "Success\n";
                    for (int i = 0; i < Resources.size(); i++)
                    {
                        std::cout << ResoursesNames[i] << ": " << printColored(Resources[i], Color::BLUE) << "   ";
                    }
                    std::cout << std::endl;
                }
                else std::cout << "You haven't enough resources" << std::endl;
            }
            else if (choiceC == 0)
                exit = 1;
            else
            {
                std::cout << "Try again" << std::endl;
            }
            PrintInventory();
            break;

        case '2':
            std::cout << "Enter two things you want to combine\nExample '2 5'\nEnter 0 0 to exit" << std::endl;
            std::cout << "Your resourses:\n";
            for (int i = 0; i < Resources.size(); i++)
            {
                std::cout << ResoursesNames[i] << ": " << printColored(Resources[i], Color::BLUE) << "   ";
            }
            std::cout << std::endl;
            PrintInventory();
            int t1, t2;
            std::cin >> t1 >> t2;
            if (t1 > 0 && t2 > 0 && t1 <= inventory.size() && t2 <= inventory.size())
            {
                std::pair<int, int> chek1 = std::make_pair(inventory[t1 - 1].first.id, inventory[t2 - 1].first.id);
                std::pair<int, int> chek2 = std::make_pair(inventory[t2 - 1].first.id, inventory[t1 - 1].first.id);
                std::pair<int, int> chek3 = std::make_pair(0, 0);
                bool found = 0;
                for (const auto& weapon : Vw)
                {
                    for (const auto& res : weapon.CraftR)
                    {
                        if (weapon.CraftR[0] != chek3)
                        {
                            if (chek1 == res || chek2 == res)
                            {
                                found = 1;
                                Weapon weaponCraft = weapon;
                                if (weaponCraft.Souls <= Resources[0] && weaponCraft.Silvers <= Resources[1] && weaponCraft.Solar_Fragments <= Resources[2])
                                {
                                    Resources[0] = Resources[0] - weapon.Souls;
                                    Resources[1] = Resources[1] - weapon.Silvers;
                                    Resources[2] = Resources[2] - weapon.Solar_Fragments;
                                    bool found1 = false;
                                    for (auto& invent : inventory)
                                    {
                                        if (weaponCraft.id == invent.first.id)
                                        {
                                            invent.second++;
                                            found1 = true;
                                            break;
                                        }
                                    }
                                    if (!found1)
                                    {
                                        inventory.emplace_back(weaponCraft, 1); // Если не нашли предмет, добавляем его
                                    }
                                    bool know = 0;
                                    for (auto& recipe : KnownRecipes)
                                    {

                                        if (weaponCraft.id == recipe.id)
                                        {
                                            know = 1;
                                        }
                                    }
                                    if (know == 0)
                                    {
                                        KnownRecipes.push_back(weaponCraft);  // Добавляем объект в вектор
                                    }

                                    Weapon weaponRemove1 = inventory[t1 - 1].first;
                                    Weapon weaponRemove2 = inventory[t2 - 1].first;

                                    std::vector<int> idsToRemove; // Вектор для хранения ID оружия, которые нужно удалить
                                    for (auto& invent : inventory)
                                    {
                                        if (weaponRemove1.id == invent.first.id)
                                        {
                                            invent.second--;
                                            if (invent.second <= 0)
                                            {
                                                idsToRemove.push_back(invent.first.id); // Добавляем ID в вектор
                                            }
                                        }
                                    }
                                    for (auto& invent : inventory)
                                    {
                                        if (weaponRemove2.id == invent.first.id)
                                        {
                                            invent.second--;
                                            if (invent.second <= 0)
                                            {
                                                idsToRemove.push_back(invent.first.id); // Добавляем ID в вектор
                                            }
                                        }
                                    }
                                    // Удаляем все элементы с ID, которые были собраны
                                    auto it = std::remove_if(inventory.begin(), inventory.end(),
                                                             [&idsToRemove](const auto& pair) {
                                                                 return std::find(idsToRemove.begin(), idsToRemove.end(), pair.first.id) != idsToRemove.end();
                                                             });
                                    inventory.erase(it, inventory.end()); // Удаляем элементы
                                    std::cout << "Success\n";
                                    for (int i = 0; i < Resources.size(); i++)
                                    {
                                        std::cout << ResoursesNames[i] << ": " << printColored(Resources[i], Color::BLUE) << "   ";
                                    }
                                    std::cout << std::endl;

                                }
                                else
                                {
                                    std::cout << "Sorry! You haven't enough resources. It's too expensive for you now(" << std::endl;
                                    std::cout << "You need: " << printColored(weaponCraft.Souls, Color::BLUE) << ", Silvers: " << 
                                        printColored(weaponCraft.Silvers, Color::BLUE) << ", Solar Fragments: " << 
                                        printColored(weaponCraft.Solar_Fragments, Color::BLUE) << std::endl;
                                }
                            }
                        }
                    }
                }
                if (found == 0)
                {
                    std::cout << "This doesn't work, try somesthing else" << std::endl;
                }
            }
            else if (t1 == t2 == 0)
                exit = 1;
            break;

        case '0':
            exit = 1;
            break;

        default: // Обрабатываем некорректный ввод
            std::cout << printColored("Error:", Color::RED) << " Try again" << std::endl;
            break;
        }
    }
}
