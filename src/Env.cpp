#include "header/Env.h"

Env::Env(){}

Env::Env(Room* r, Player* p) : root_room(r), pc(p){
  loc = root_room;
}

Env::Env(std::ifstream& istrm){
  std::string pc_name;
  istrm >> pc_name;
  Player pc_tmp = Player(pc_name);
  pc = &pc_tmp;
  Room tmp(istrm);
  root_room = &tmp;
  loc = root_room;
}

std::string Env::get_char_name(){ 
  return pc->get_name(); 
}

Room* Env::get_loc(){ return loc; }

Player* Env::get_pc(){ return pc; }
