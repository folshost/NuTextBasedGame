#ifndef ENV_H
#define ENV_H

#include "Room.h"
#include "Player.h"

#include <fstream>
#include <memory>
#include <vector>

class Env{
private:
  std::shared_ptr<Room> root_room;
  std::shared_ptr<Room> loc;
  std::shared_ptr<Player> pc;
public:
  Env();
  Env(std::shared_ptr<Room> r, std::shared_ptr<Player> p);
  Env(std::vector<Room> r, std::shared_ptr<Player> p);
  Env(std::ifstream& istrm);

  std::string get_char_name();

  std::shared_ptr<Room> get_loc();

  std::shared_ptr<Player> get_pc();
};
#endif
