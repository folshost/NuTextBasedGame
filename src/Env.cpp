#include "header/Env.h"

#include <ctime>
#include <random>

namespace detail {
  int get_random_direction() {
    return std::rand() % 4;
  }

  void populate_map(Room& r, std::vector<Room> v) {
    if (v.size() == 0)
      return;
    

  }
}

Env::Env(){}

Env::Env(std::shared_ptr<Room> r, std::shared_ptr<Player> p) : root_room(r), pc(p){
  loc = root_room;
}

Env::Env(std::vector<Room> r, std::shared_ptr<Player> p) {
  std::srand(std::time(nullptr));
  int root_room = std::rand() % r.size();

}

Env::Env(std::ifstream& istrm){
  std::string pc_name;
  istrm >> pc_name;
  pc = std::make_shared<Player>(pc_name);
  root_room = std::make_shared<Room>(istrm);
  loc = root_room;
}

std::string Env::get_char_name(){ 
  return pc->get_name(); 
}

std::shared_ptr<Room> Env::get_loc(){ return loc; }

std::shared_ptr<Player> Env::get_pc(){ return pc; }
