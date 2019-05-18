#ifndef ITEM_H
#define ITEM_H

#include <fstream>
#include <string>

class Item{
private:
  std::string name;
  int xp_val;

public:
  Item(std::string n, int val);

  Item(std::ifstream& istrm);

  int get_xp();

  std::string get_name();

  void write(std::ofstream& ostrm);
};
#endif
