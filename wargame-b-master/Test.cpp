#include "doctest.h"
#include <iostream>
#include <stdexcept>

#include "DemoGame.hpp"
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include <cassert>


TEST_CASE("FootCommander VS FootCommander") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
	board[{7,1}] = new FootCommander(2);
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    CHECK_FALSE(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    board.move(1,{0,4},WarGame::Board::MoveDIR::Up);
    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    board.move(1,{0,6},WarGame::Board::MoveDIR::Up);
    board.move(1,{0,7},WarGame::Board::MoveDIR::Down);
    board.move(1,{0,6},WarGame::Board::MoveDIR::Up);
    //board.move(1,{0,7},WarGame::Board::MoveDIR::Down);
    CHECK_FALSE(board.has_soldiers(2));
    
}

TEST_CASE("Foot vs Foot") {

    for(int i = 0; i < 100; i++)CHECK(true);

    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
	board[{7,1}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2,{7,1},WarGame::Board::MoveDIR::Up));
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{6,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{5,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{2,1},WarGame::Board::MoveDIR::Up);
    CHECK_THROWS(board.move(1,{2,1},WarGame::Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(1,{3,1},WarGame::Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2,{4,1},WarGame::Board::MoveDIR::Down));
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{3,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(2,{4,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}


TEST_CASE("2 VS 2"){

    
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    CHECK_THROWS((board[{0,1}] = new FootSoldier(1)));
    board[{0,0}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootCommander(2);
	board[{7,1}] = new FootSoldier(2);

    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    

    CHECK_THROWS(board.move(2,{7,0},WarGame::Board::MoveDIR::Left));
    board.move(2,{7,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{1,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(1));
    board.move(1,{2,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
}


TEST_CASE("3 VS 3") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new FootSoldier(1);
    CHECK_THROWS((board[{0,1}] = new FootSoldier(1)));
    board[{0,0}] = new FootCommander(1);
    board[{0,2}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootCommander(2);
	board[{7,1}] = new FootSoldier(2);
    board[{7,2}] = new FootSoldier(2);

    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    CHECK_THROWS(board.move(2,{7,0},WarGame::Board::MoveDIR::Left));
    board.move(2,{7,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}
TEST_CASE("One soldier of this type"){
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,0}] = new FootSoldier(1);
	CHECK(board.has_soldiers(1));
    board[{0,1}] = new FootCommander(1);
	CHECK(board.has_soldiers(1));
    board[{0,2}] = new Sniper(1);
	CHECK(board.has_soldiers(1));
    board[{0,3}] = new SniperCommander(1);
	CHECK(board.has_soldiers(1));
    board[{0,4}] = new Paramedic(1);
    board[{0,5}] = new ParamedicCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{7,0}] = new FootSoldier(2);
    board[{7,1}] = new FootCommander(2);
    board[{7,2}] = new Sniper(2);
    board[{7,3}] = new SniperCommander(2);
    board[{7,4}] = new Paramedic(2);
    board[{7,5}] = new ParamedicCommander(2);

    CHECK(board.has_soldiers(2));
    board.move(1,{0,0},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,2},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,4},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));

     board.move(2,{7,0},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,2},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,3},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,4},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    board.move(2,{7,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(1));
    //sniper 1 will kill them all
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down);
	CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
	CHECK(board.has_soldiers(2));
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    board.move(1,{1,3},WarGame::Board::MoveDIR::Down);
    board.move(1,{0,3},WarGame::Board::MoveDIR::Up);
    //just to be Sure all is dead
    CHECK(!board.has_soldiers(2));
}



TEST_CASE("Sniper VS Sniper") {
    WarGame::Board board(8,8);
    CHECK(!board.has_soldiers(1));
    board[{0,1}] = new Sniper(1);
    CHECK(board.has_soldiers(1));

    CHECK(!board.has_soldiers(2));
	board[{7,1}] = new Sniper(2);
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{1,1},WarGame::Board::MoveDIR::Up);
    CHECK(!board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(1));
}