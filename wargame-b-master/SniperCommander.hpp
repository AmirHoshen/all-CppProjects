#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

#define SC_HP 120
#define SC_DPA 100

class SniperCommander : public Sniper
{
public:
    SniperCommander(int team) : Sniper(SC_HP, SC_DPA, team, true, Soldier::Sniper){};
    ~SniperCommander(){};
    void heal() override
    {
        _hp = SC_HP;
    }
};
