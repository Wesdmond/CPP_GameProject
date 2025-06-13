#include "class.h"

Weapon::Weapon(int ID, std::string NAME, int dmg, std::vector<std::pair<int, int>> cr, int Souls, int Silvers, int Solar_Fragments)
    : id(ID), name(NAME), DMG(dmg), CraftR(cr), Souls(Souls), Silvers(Silvers), Solar_Fragments(Solar_Fragments) {}

std::string Weapon::to_string() const
{
    std::stringstream ans;
    ans << id << '\n' << name << '\n' << DMG << '\n' << CraftR.size();
    for (const auto& craft : CraftR)
    {
        ans << craft.first << ' ' << craft.second << '\n';
    }
    ans << Souls << ' ' << Silvers << ' ' << Solar_Fragments;
    return ans.str();
}


Creations::Creations(int ID, std::string NAME, int hp, int dmg, int Souls, int Silvers, int Solar_Fragments)
    : id(ID), name(NAME), MAX_HP(hp), DMG(dmg), Souls(Souls), Silvers(Silvers), Solar_Fragments(Solar_Fragments) {}

bool is_new_game = true;