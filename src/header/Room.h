#ifndef ROOM_H
#define ROOM_H

#include "Item.h"

#include <fstream>
#include <optional>
#include <memory>
#include <string>
#include <vector>

class Room : std::enable_shared_from_this<Room>{
private:
  std::string name;
  int north, east, south, west;
  std::vector<Item> items_;
  std::vector<Room>& room_list;

public:
  Room(std::vector<Room>&);
  Room(const Room& in);
  Room(Room&& in);
  Room(std::string n, std::vector<Item> i, std::vector<Room>& rl);
  Room(std::ifstream& istrm, std::vector<Room>& rl);
  
  ~Room();

  Room& operator=(const Room&);
  Room& operator=(Room&&);

  void setN(int n);
  void setE(int e);
  void setS(int s);
  void setW(int w);
  void setDir(int idx, int val);

  int getN() const;
  int getE() const;
  int getS() const;
  int getW() const;
  int getDir(int idx) const;

  std::string get_name() const;

  std::vector<Room>& get_room_list() const;

  std::vector<Item> get_items() const;

  void set_items(std::vector<Item> items);

  void write(std::ofstream& ostrm);

};


#endif
