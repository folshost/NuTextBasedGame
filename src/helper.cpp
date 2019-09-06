#include "header/helper.h"

void print_item_list(std::vector<Item> k){
  for(int i = 0; i < k.size(); i++){
    std::cout << k[i].get_name() << std::endl;
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

void help(){
    std::cout << "You can 'look' around, 'get' items, and try to" <<
    std::endl << "leave the planet with the materials you have so far" <<
    std::endl << "by 'ascending'. You can also look at your inventory" <<
    std::endl << "with 'inv', and say 'help' to get this message" <<
    std::endl;
}

void look(std::vector<Item> k){
    std::cout << "You look around" << std::endl;
    if(k.size() > 0){
      std::cout << "There are the following items around" << std::endl;
      print_item_list(k);
    }
    else
      std::cout << "There is nothing here" << std::endl;
}

void ls(std::vector<Item> k){
  std::cout << "You somehow mistake this game for a UNIX terminal" << std::endl;
  look(k);
}

void inv(std::vector<Item> k){
  if(k.size() > 0){
    std::cout << "Your inventory contains: " << std::endl;
    print_item_list(k);
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




