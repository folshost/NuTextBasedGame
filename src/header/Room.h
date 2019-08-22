#ifndef ROOM_H
#define ROOM_H

#include "Item.h"

#include <fstream>
#include <optional>
#include <memory>
#include <string>
#include <vector>

class Room{
private:
  std::string name;
  std::shared_ptr<Room> self = std::shared_ptr<Room>(this);
  std::shared_ptr<Room> north, east, south, west;
  std::vector<Item> items_;

public:
  //Room();
  Room(const Room& in);
  Room(std::string n, std::vector<Item> i);
  Room(std::ifstream& istrm);
  
  ~Room();

  Room& operator=(const Room&);

  void setN(std::shared_ptr<Room> n);
  void setE(std::shared_ptr<Room> e);
  void setS(std::shared_ptr<Room> s);
  void setW(std::shared_ptr<Room> w);

  std::shared_ptr<Room> getN() const;
  std::shared_ptr<Room> getE() const;
  std::shared_ptr<Room> getS() const;
  std::shared_ptr<Room> getW() const;

  std::string get_name() const;

  std::vector<Item> get_items() const;

  void set_items(std::vector<Item> items);

  void write(std::ofstream& ostrm);

  std::shared_ptr<Room> get_self() const;
};


#endif
