#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"

#include <vector>

class Player{
private:
  int hp;
  int total_xp;
  std::string name;
  std::vector<Item> inventory;

public:
  Player(std::string n);

  void pickUpItem(Item n);

  std::string get_name();

  int get_level();

  std::vector<Item> get_inventory();
};
#endif
