#include "header/Room.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

Room::Room(std::vector<Room>& rl) : name("_null"), room_list(rl), north(0), east(0), south(0), west(0) { }

Room::Room(const Room& in) : name(in.get_name()+"_"), items_(in.get_items()), room_list(in.get_room_list()), north(in.getN()), east(in.getE()), south(in.getS()), west(in.getW()) 
{
  std::cout << "Copy constructor" << std::endl;
}

Room::Room(Room && in) : name(in.get_name() + "+"), items_(in.get_items()), room_list(in.get_room_list()), north(in.getN()), east(in.getE()), south(in.getS()), west(in.getW())
{
  std::cout << "Move construction" << std::endl;
}

Room::Room(std::string n, std::vector<Item> i, std::vector<Room>& rl) : name(n), items_(i), room_list(rl), north(0), east(0), south(0), west(0)
{ 
  std::cout << "Name and items construction" << std::endl;
}

Room::Room(std::ifstream& istrm, std::vector<Room>& rl) : items_(std::vector<Item>()), room_list(rl), north(0), east(0), south(0), west(0)
{ 
  std::cout << "istrm construction" << std::endl;
  istrm >> name;
  
  if( name == "null" ){
    return;
  }
  int size = 0;
  istrm >> size;
  for(int i = 0; i < size; i++){
    Item tmp = Item(istrm);
    items_.push_back(tmp);
  }  
}

Room::~Room() {
	std::cout << "I am being destructed, " << name << std::endl;
}

Room& Room::operator=(const Room& in)
{
  std::vector<Item> k = in.get_items();
  std::cout << "Copy Assignment: " << k.size() << std::endl;
  set_items(k);
  if (in.getN())
    setN(in.getN());
  if (in.getE())
    setE(in.getE());
  if (in.getS())
    setS(in.getS());
  if (in.getW())
    setW(in.getW()); 
  return *this;
}

Room& Room::operator=(Room && in)
{

  std::vector<Item> k = in.get_items();
  std::cout << "Move Assignment: " << k.size() << std::endl;
  set_items(k);
  if (in.getN())
    setN(in.getN());
  if (in.getE())
    setE(in.getE());
  if (in.getS())
    setS(in.getS());
  if (in.getW())
    setW(in.getW());
  return *this;
}

void Room::setN(int n) { north = n; }
void Room::setE(int e) { east = e; }
void Room::setS(int s) { south = s; }
void Room::setW(int w) { west = w; }
void Room::setDir(int idx, int val) {
  if (idx == 1)
    setN(val);
  else if (idx == 2)
    setE(val);
  else if (idx == 3)
    setS(val);
  else if (idx == 4)
    setW(val);
  else
    throw;
}

int Room::getN() const { return north; }
int Room::getE() const { return east; }
int Room::getS() const { return south; }
int Room::getW() const { return west; }
int Room::getDir(int idx) const {
  if (idx == 1)
    return north;
  else if (idx == 2)
    return east;
  else if (idx == 3)
    return south;
  else if (idx == 4)
    return west;
  else
    throw;
}

std::string Room::get_name() const{ 
  return name; 
}

std::vector<Item> Room::get_items() const{ 
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
  /*
  north->write(ostrm);
  east->write(ostrm);
  south->write(ostrm);
  west->write(ostrm);
  */
}

std::vector<Room>& Room::get_room_list() const { return room_list; }

