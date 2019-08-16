#include "header/Room.h"

#include <chrono>
#include <iostream>
#include <thread>

Room::Room() : items_(std::vector<Item>()), north(Room()){ }

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
  Room n = Room(istrm);
  north = n;
  Room e = Room(istrm);
  east = e;
  Room s = Room(istrm);
  south = s;
  Room w = Room(istrm);
  west = w;
}

Room::~Room() {
	std::cout << "I am being destructed, " << name << std::endl;
}

void Room::setN(Room& n) { north = n; }
void Room::setE(Room& e) { east = e; }
void Room::setS(Room& s) { south = s; }
void Room::setW(Room& w) { west = w; }

Room& Room::getN() { return north; }
Room& Room::getE() { return east; }
Room& Room::getS() { return south; }
Room& Room::getW() { return west; }

std::string Room::getName(){ 
  return name; 
}

std::vector<Item>& Room::get_items(){ 
  std::cout << "Inside get_items" << std::endl;
  return items_;
}

void Room::set_items(std::vector<Item> items){ 
  items_ = items; 
}

void Room::write(std::ofstream& ostrm){
  ostrm << name << std::endl;
  if (name == "null")
    return;
  ostrm << items_.size();
  for(uint64_t i = 0; i < items_.size(); i++){
    items_[i].write(ostrm);
  }
  north.write(ostrm);
  east.write(ostrm);
  south.write(ostrm);
  west.write(ostrm);
}
