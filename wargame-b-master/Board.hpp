/**
 * Header file for the board of the war game.
 * 
 * You can copy this file to a new file called Board.hpp, and extend it as you like.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */
#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <stdint.h>
#include "Soldier.hpp"

#ifndef uint
#define uint unsigned int
#endif
namespace WarGame
{

  class Board
  {
  private:
    std::vector<std::vector<Soldier *>> board;

  public:
    enum MoveDIR
    {
      Up,
      Down,
      Right,
      Left
    };

    Board(uint numRows, uint numCols) : board(numRows, std::vector<Soldier *>(numCols, nullptr)) {}

    // operator for putting soldiers on the game-board during initialization.
    Soldier *&operator[](std::pair<int, int> location);

    // operator for reading which soldiers are on the game-board.
    Soldier *operator[](std::pair<int, int> location) const;

    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument".
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers
    //      must be handled by polymorphism.
    void move(uint player_number, std::pair<int, int> source, MoveDIR direction);

    // returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint player_number) const;

    ~Board()
    {
      board.clear();
    }

    bool isEmpty(std::pair<int, int> location)
    {
      int row = location.first;
      int col = location.second;
      if (row >= board.size() || col >= board[0].size() || row < 0 || col < 0)
      {
        throw std::invalid_argument("Bad location");
      }
      Soldier *tmp = this->board[row][col];
      if (tmp == nullptr)
        return true;
      throw std::invalid_argument("place is taken");
    }

    void attack(std::pair<int, int> loc, Soldier *soldier);
  };

} // namespace WarGame
