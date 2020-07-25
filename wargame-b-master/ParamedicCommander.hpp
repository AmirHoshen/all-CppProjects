#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Paramedic.hpp"

#define PC_HP 200
#define PC_DPA 200

class ParamedicCommander : public Paramedic{
    public:
    ParamedicCommander(int team): Paramedic(PC_HP, PC_DPA, team, true, Soldier::Paramedic){};
    ~ParamedicCommander(){};
    
    void heal()override{
        _hp = PC_HP;
    }
};
