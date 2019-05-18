#include "header/Room.h"

#include <chrono>
#include <iostream>
#include <thread>

Room::Room(std::string n, std::vector<Item> i) : name(n), items_(i){ };

Room::Room(std::ifstream& istrm){
  //using namespace std::chrono_literals;
  //std::cout << "\tGetting room name!" << std::endl;
  istrm >> name;
  //std::cout << "\tGot a room name! " << name << std::endl;
  //int in = 0;
  //std::cin >> in;
  if( name == "null" ){
    items_ = std::vector<Item>();
    return;
  }
  int size = 0;
  istrm >> size;
  //std::cout << "Size = " << size << std::endl;
  //std::cin >> in;
  for(int i = 0; i < size; i++){
    Item tmp = Item(istrm);
    items_.push_back(tmp);
  }
  Room n(istrm);
  north = &n;
  Room e(istrm);
  east = &e;
  Room s(istrm);
  south = &s;
  Room w(istrm);
  west = &w;
}

void Room::setN(Room* n) { north = n; }
void Room::setE(Room* e) { east = e; }
void Room::setS(Room* s) { south = s; }
void Room::setW(Room* w) { west = w; }

Room* Room::getN() { return north; }
Room* Room::getE() { return east; }
Room* Room::getS() { return south; }
Room* Room::getW() { return west; }

std::string Room::getName(){ 
  return name; 
}

std::vector<Item>& Room::get_items(){ 
  return items_;
}

void Room::set_items(std::vector<Item> items){ 
  items_ = items; 
}

void Room::write(std::ofstream& ostrm){
  ostrm << name << std::endl;
  ostrm << items_.size();
  for(int i = 0; i < items_.size(); i++){
    items_[i].write(ostrm);
  }
  north->write(ostrm);
  east->write(ostrm);
  south->write(ostrm);
  west->write(ostrm);
}
