#ifndef ENV_H
#define ENV_H

#include "Room.h"
#include "Player.h"

#include <fstream>

class Env{
private:
  Room* root_room;
  Room* loc;
  Player* pc;
public:
  Env();
  Env(Room* r, Player* p);
  Env(std::ifstream& istrm);

  std::string get_char_name();

  Room* get_loc();

  Player* get_pc();
};
#endif
