#pragma once
#include <vector>

#include <sstream>
class Weapon {
public:
    std::vector<std::pair <int, int>>CraftR;
    std::string name;
    int id;
    int DMG;
    int Souls;
    int Silvers;
    int Solar_Fragments;
    Weapon(int ID, std::string NAME, int dmg, std::vector<std::pair<int, int>> cr, int Souls, int Silvers, int Solar_Fragments);
    std::string to_string() const;
};

class Creations {
public:
    int id;
    std::string name;
    int MAX_HP;
    int DMG;
    int Souls;
    int Silvers;
    int Solar_Fragments;
    Creations(int ID, std::string NAME, int hp, int dmg, int Souls, int Silvers, int Solar_Fragments);
};

extern std::vector<Weapon> Vw;
extern std::vector<Creations> Vc;
extern std::vector<std::pair<int, int>> Ve;
extern std::vector<std::vector<int>> array;
extern std::vector<std::pair<Weapon, int>> inventory;
extern std::vector<Weapon> KnownRecipes;
extern std::vector<int> Resources;
const std::vector<std::string> ResoursesNames = { "Souls", "Silvers", "Solar Fragments" };
extern Weapon WeaponEquiped;
extern bool is_new_game;