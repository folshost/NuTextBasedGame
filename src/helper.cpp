#include "header/helper.h"

void print_item_list(Env& e){
  if (e.get_current_room().get_items().size() > 0) {
    std::cout << "The following items are visible" << std::endl;
    std::vector<Item>& k = e.get_current_room().get_items();
    for(int i = 0; i < k.size(); i++){
      std::cout << k[i].get_name() << std::endl;
    }
  }
  else
    std::cout << "There are no items here" << std::endl;
}

void print_room_list(Env& e) {
  std::vector<std::string> dirs{"north", "east", "south", "west"};
  Room& here = e.get_current_room();
  for(int i = 1; i < 5; i++) {
    if (here.getDir(i) != -1)
      std::cout << "There is a path to the " << e.get_rooms_ref()[here.getDir(i)].get_name() << " here to the " << dirs[i - 1] << std::endl;
  }
}

void get_item(Env e){
    std::cout << "Get what item?" << std::endl;
    std::string item_to_get;
    std::cin >> item_to_get;
    bool found = false;
    std::vector<Item> its = e.get_current_room().get_items();
    for(auto it = its.begin(); it != its.end(); ){
      if((*it).get_name() == item_to_get){
        e.get_pc().pickUpItem(*it);
        its.erase(it);
        found = true;
      }
      else{
        it++;
      } 
    }
    if(found){
      std::cout << item_to_get << " is now in inventory." << std::endl;
    }
    else{
      std::cout << item_to_get << " not found." << std::endl;
    }
}

void go(Env& e, std::string i)
{
  if (i.find("north") != std::string::npos) {
    if (e.get_current_room().getN() != -1) {
      e.travelDir(1);
    }
  }
  else if (i.find("east") != std::string::npos) {
    if (e.get_current_room().getE() != -1) {
      e.travelDir(2);
    }
  }
  else if (i.find("south") != std::string::npos) {
    if (e.get_current_room().getS() != -1) {
      e.travelDir(3);
    }
  }
  else if (i.find("west") != std::string::npos) {
    if (e.get_current_room().getW() != -1) {
      e.travelDir(4);
    }
  }
  else {
    std::cout << "Direction not understood" << std::endl;
  }
  look(e);
}

void help(){
    std::cout << "You can 'look' around, 'get' items, and try to" <<
    std::endl << "leave the planet with the materials you have so far" <<
    std::endl << "by 'ascending'. You can also look at your inventory" <<
    std::endl << "with 'inv', and say 'help' to get this message" <<
    std::endl;
}

void look(Env& e){
    std::cout << "You look around" << std::endl;
    std::cout << "You are in the " << e.get_current_room().get_name() << std::endl;
    print_item_list(e);
    print_room_list(e);
}

void ls(Env& e){
  std::cout << "You somehow mistake this game for a UNIX terminal" << std::endl;
  look(e);
}

void inv(Env& e){
  if(e.get_pc().get_inventory().size() > 0){
    std::cout << "Your inventory contains: " << std::endl;
    print_item_list(e);
  }
  else
    std::cout << "You have nothing in your inventory" << std::endl;
}

int ascend(int level){
  if(level > 10){
    std::cout << "You successfully construct the space ship you've been\n" <<
                 "trying to build and leave the planet" << std::endl;
    return 1;
  }
  else{
    std::cout << "You do not have the materials to make that possible" <<
    std::endl;
    return 0;
  }
}




