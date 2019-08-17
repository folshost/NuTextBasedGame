#include "header/Env.h"

Env::Env(){}

Env::Env(std::shared_ptr<Room> r, std::shared_ptr<Player> p) : root_room(r), pc(p){
  loc = root_room;
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
