#ifndef ROOM_H
#define ROOM_H

#include "Item.h"

#include <fstream>
#include <string>
#include <vector>

class Room{
private:
  std::string name;
  Room& north,& east,& south,& west;
  std::vector<Item>& items_;

public:
  Room();
  Room(std::string n, std::vector<Item> i);
  Room(std::ifstream& istrm);
  
  void operator=(const Room&);

  void setN(Room& n);
  void setE(Room& e);
  void setS(Room& s);
  void setW(Room& w);

  Room& getN();
  Room& getE();
  Room& getS();
  Room& getW();

  std::string getName();

  std::vector<Item>& get_items();

  void set_items(std::vector<Item> items);

  void write(std::ofstream& ostrm);
};


#endif
