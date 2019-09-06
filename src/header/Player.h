#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"

#include <vector>

class Player{
private:
  // hp can be a function of total_xp (an implicit "level" just take total_xp % 10 or something)
  // it will change on getting more xp and triggering a level
  int hp;
  int total_xp;
  std::string name;
  std::vector<Item> inventory;

public:
  Player(std::string n);
  Player(std::ifstream& istrm);

  void pickUpItem(Item n);

  std::string get_name();

  int get_level();

  std::vector<Item> get_inventory();
};
#endif
