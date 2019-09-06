#ifndef ENV_H
#define ENV_H

#include "Room.h"
#include "Player.h"

#include <fstream>
#include <memory>
#include <vector>

class Env{
private:
  int loc_;
  Player pc_;
  std::vector<Room> rooms_;
public:
  Env();
  Env(Player& p);
  /*
  Env(Env&);
  Env(Env&&);
  Env& operator=(const Env&);
  Env& operator=(Env&&);
  */
  Env(std::vector<Room>& r, Player& p);
  Env(std::ifstream& istrm);

  std::string get_char_name();

  Room& get_current_room();

  std::vector<Room>& get_rooms_ref();

  Player& get_pc();

  void travelDir(int dir);
};
#endif
