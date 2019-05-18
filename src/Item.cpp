#include "header/Item.h"

Item::Item(std::string n, int val) : name(n), xp_val(val) { }

Item::Item(std::ifstream& istrm) {
  istrm >> name >> xp_val;
}

int Item::get_xp(){ return xp_val; }

std::string Item::get_name() { return name; }

void Item::write(std::ofstream& ostrm){
  ostrm << name << xp_val;
}
