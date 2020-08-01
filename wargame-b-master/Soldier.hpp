#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

class Soldier{
public:
    enum Type{
        FootSoldier,
        Sniper,
        Paramedic,
    };
    int _hp;
    int _dpa;
    int _team;
    bool _isCommander;
    Type _type;

    Soldier(int hp, int dpa, int team, bool commander, Type type): _hp(hp), _dpa(dpa), _team(team), _isCommander(commander), _type(type){}
    virtual ~Soldier(){};
    virtual void attack(std::vector<std::vector<Soldier*>> &board, std::pair<int,int> source) =0;
    virtual void specialAttack(std::vector<std::vector<Soldier*>> &board, std::pair<int, int> source) = 0;
    virtual void heal() = 0;
    /*
       if we want all soldier to play together at one time
       *
      void playAll(std::vector<std::vector<Soldier *>> &board, Type type){
            for(int i = 0 ; i < board.size() ; ++i ){
                  for(int j = 0 ; j < board[i].size() ; ++j ){
                        if(board[i][j] != nullptr && board[i][j]->_team == this->_team && board[i][j]->_type == type)
                        board[i][j]->specialAttack(board , {i,j});
                  }
            }
      }  */
};
