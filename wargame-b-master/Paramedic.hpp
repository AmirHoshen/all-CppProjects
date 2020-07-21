#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "FootSoldier.hpp"

#define P_HP 100
#define P_DPA 200

class Paramedic : public FootSoldier{
public:
    Paramedic(int team):FootSoldier(P_HP, P_DPA, team, false, Soldier::Paramedic){};
    Paramedic(int hp, int dpa, int team, bool isCommander, Type type) : FootSoldier(hp, dpa, team, isCommander, type) {}
    ~Paramedic(){};
    void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        std::cout << "Paramedic heal\n";
        
        int i = source.first;
        int j = source.second;
        Soldier* tmp;
        if (i - 1 >= 0 && j - 1 >= 0){
            tmp = board[i-1][j-1];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }

        if (j - 1 >= 0){
            tmp = board[i][j-1];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }

        if (i + 1 < board.size() && j - 1 >= 0){
            tmp = board[i+1][j-1];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }

        if (i - 1 > 0){
            tmp = board[i-1][j];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }

        if (i + 1 < board.size()){
            tmp = board[i+1][j];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }

        if (i - 1 >= 0 && j + 1 < board[0].size()){
            tmp = board[i-1][j+1];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }

        if (j + 1 < board[0].size()){
            tmp = board[i+1][j];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }

        if (i + 1 >= 0< board.size() && j + 1 < board[0].size()){
            tmp = board[i+1][j+1];
            if(tmp != nullptr && tmp->_team == _team) tmp->heal();
        }
    }
    void specialAttack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) override{
        attack(board, source);
        
        if(_isCommander){
            std::cout << "Paramedic Commander heal\n";
            for (int i = 0; i < board.size(); i++)
            {
                std::vector<Soldier *> a = board[i];
                for (int j = 0; j < a.size(); j++)
                {
                    Soldier *s = a[j];
                    if (s != NULL && s->_team == _team && !s->_isCommander && s->_type == _type)
                        s->specialAttack(board, {i, j});
                }
            }
        }
    }
    void heal() override{
        _hp = P_HP;
    }

};
