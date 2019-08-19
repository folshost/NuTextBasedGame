#include "header/Room.h"

#include <chrono>
#include <iostream>
#include <thread>

//Room::Room() : self(std::make_shared<Room>(this)), north(self), east(self), south(self), west(self) { }

Room::Room(Room& in) : name(in.get_name()), items_(in.get_items()), self(in.get_self()), north(in.getN()), east(in.getE()), south(in.getS()), west(in.getW()) {}

Room::Room(std::string n, std::vector<Item> i) : self(std::shared_ptr<Room>(this)), name(n), items_(i), north(self),
               east(self), south(self), west(self) { }

Room::Room(std::ifstream& istrm) : self(std::shared_ptr<Room>(this)), items_(std::vector<Item>()), north(self), east(self), south(self), west(self) { 

  //using namespace std::chrono_literals;
  //std::cout << "\tGetting room name!" << std::endl;
  istrm >> name;
  //std::cout << "\tGot a room name! " << name << std::endl;
  //int in = 0;
  //std::cin >> in;
  
  if( name == "null" ){
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
  north = std::make_shared<Room>(istrm);
  north->setS(self);
  east = std::make_shared<Room>(istrm);
  east->setW(self);
  south = std::make_shared<Room>(istrm);
  south->setN(self);
  west = std::make_shared<Room>(istrm);
  west->setE(self);  
}

Room::~Room() {
	std::cout << "I am being destructed, " << name << std::endl;
}

void Room::operator=(Room& in)
{
  self = std::unique_ptr<Room>(this);
  std::vector<Item> k = in.get_items();
  std::cout << k.size() << std::endl;
  set_items(k);
  if (in.getN() != in.get_self())
    setN(in.getN());
  else
    setN(self);
  if (in.getE() != in.get_self())
    setE(in.getE());
  else
    setE(self);
  if (in.getS() != in.get_self())
    setS(in.getS());
  else
    setS(self);
  if (in.getW() != in.get_self())
    setW(in.getW());
  else
    setW(self);  
}

void Room::setN(std::shared_ptr<Room> n) { north = n; }
void Room::setE(std::shared_ptr<Room> e) { east = e; }
void Room::setS(std::shared_ptr<Room> s) { south = s; }
void Room::setW(std::shared_ptr<Room> w) { west = w; }

std::shared_ptr<Room> Room::getN() const { return north; }
std::shared_ptr<Room> Room::getE() const { return east; }
std::shared_ptr<Room> Room::getS() const { return south; }
std::shared_ptr<Room> Room::getW() const { return west; }

std::string Room::get_name(){ 
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
  north->write(ostrm);
  east->write(ostrm);
  south->write(ostrm);
  west->write(ostrm);
}

std::shared_ptr<Room> Room::get_self() { return self; }
