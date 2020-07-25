#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "Soldier.hpp"

#define FS_HP 100
#define FS_DPA 10

class FootSoldier : public Soldier
{
public:
    FootSoldier(int team) : Soldier(FS_HP, FS_DPA, team, false, Soldier::FootSoldier){};
    FootSoldier(int hp, int dpa, int team, bool isCommander, Type type) : Soldier(hp, dpa, team, isCommander, type){}
    ~FootSoldier(){};
    void attack(std::vector<std::vector<Soldier *>> &board, std::pair<int, int> source) override
    {
        std::pair<int,int> enemyPosition = findClosestEnemy(board, source);
        if(enemyPosition.first<0 || enemyPosition.second<0 || enemyPosition.first >= board.size() || enemyPosition.second >=board[0].size())
        {
            std::cout<< "Error enemy position is out of bounds! \n"<<std::endl;
            return;
        }
        std::cout<< enemyPosition.first << " "<< enemyPosition.second <<std::endl;
        Soldier *enemy = board[enemyPosition.first][enemyPosition.second];
        enemy->_hp -= _dpa;
        std::cout<<"DPA is :   "<<_dpa<<" , enemy hp after attack is : "<<enemy->_hp<<"\n"<<std::endl;
        if(enemy->_hp <=0){
            delete enemy;
            board[enemyPosition.first][enemyPosition.second] = nullptr;
            std::cout <<" Enemy spotted and terminated!, roger"<<std::endl;
        }
    }
    void specialAttack(std::vector<std::vector<Soldier *>> &board, std::pair<int,int> source) override {
        if (!_isCommander) {
            std::cout << "-->FootSoldier Attack<--" << std::endl;
            attack(board, source);
        }
        else if(_isCommander){
            std::cout<<"-->FootCommander Attack<--"<<std::endl;
            for(int i=0; i<board.size() ; ++i){
                std::vector<Soldier *> a = board[i];
                for(int j=0; j<a.size(); ++j){
                    Soldier *s = a[j];
                    if(s!=NULL && s->_team == _team && !s->_isCommander && s->_type == _type) s->specialAttack(board, {i,j});
                }
            }
        }
    }
    void heal() override
    {
        _hp = FS_HP;
    }

    std::pair<int,int> findClosestEnemy(std::vector<std::vector<Soldier *>> &board, std::pair<int,int> source){
        std::pair<int,int> ans = {-1,-1};
        std::cout<<"The closest enemy is at position : "<< std::endl;
        double distance = board.size()*board.size();
        for(int i=0; i<board.size(); ++i){
            std::vector<Soldier *> a =board[i];
            for(int j=0; j<a.size(); ++j){
                Soldier *s = a[j];
                if(s != NULL && s->_team != this->_team){
                    std::pair<int,int> end = {i,j};
                    double tmp = distanceFunc(source, end);
                    if(tmp <distance){
                        distance = tmp;
                        ans = {i,j};
                    }
                }
            }
        }
    return ans;
    }

    double distanceFunc(std::pair<int, int> source, std::pair<int, int> end){
        int x1,y1,x2,y2;
        x1 = source.first;
        x2 = end.first;
        y1 = source.second;
        y2 = end. second;
        return sqrt(pow(x2 -x1, 2) + pow(y2 -y1, 2));
    }
};
