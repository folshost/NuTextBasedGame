#include "header/Player.h"

Player::Player(std::string n) : name(n), total_xp(0){ }

void Player::pickUpItem(Item n){
  inventory.push_back(n);
  total_xp += n.get_xp();
}

std::string Player::get_name(){ 
  return name; 
}

int Player::get_level(){ 
  return total_xp / 10; 
}

std::vector<Item> Player::get_inventory(){ 
  return inventory; 
}
