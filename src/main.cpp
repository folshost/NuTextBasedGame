#include "header/helper.h"
#include "header/file_helper.h"

#include "header/Env.h"
#include "header/Item.h"
#include "header/Player.h"
#include "header/Room.h"
//#include "header/Saves.h"

//#include <experimental/filesystem>
#include <iostream>
#include <sstream>
#include <vector>

Room null_room(std::string("null"), std::vector<Item>());

int main_input_loop(Env e){
  std::string input = "";
  std::cin >> input;
  if( input == "look"){
	auto loc = e.get_loc();
	std::cout << "Got the location" << std::endl;
	auto items = loc->get_items();
    look(items);
  }
  else if( input == "ls" ){
    ls(e.get_loc()->get_items());
  }
  else if( input == "i" || input == "inv" || input == "inventory"){
    inv(e.get_pc()->get_inventory());
  } 
  else if( input == "get"){
    get_item(e);
  }
  else if( input == "ascend"){
    return ascend(e.get_pc()->get_level());
  }
  else if( input == "help"){
    help();
  }
  else if( input == "quit" || input == "exit" ){
    return 1;
  } 
  else{
    std::cout << "Sorry, that does not compute" << std::endl;
  }
  return 0;
}

Env new_game(){
  std::cout << "Starting new game" << std::endl;
  std::cout << "Please enter the character name" << std::endl;
  std::string name;
  std::cin >> name;
  std::shared_ptr<Player> pc = std::make_shared<Player>(name);
  std::vector<Room> rooms = get_rooms();
  std::cout << rooms[0].get_self()->get_name() << std::endl;

  std::shared_ptr<Room> root_room = std::make_shared<Room>(std::ifstream("rooms.dat"));
  Env e(root_room, pc);
  return e;
}

Env previous_game(std::vector<std::string> saves_){
  std::cout << "Previous games were found on file." << std::endl;
  std::cout << "Would you like to open one? (y/n)" << std::endl;
  std::string input = "";
  bool open_prev = false;
  while(true){
    std::cin >> input;
    if( input == "y" || input == "yes" || input == "ye" ){
      open_prev = true;
    }
    else if ( input == "n" || input == "no" ){
      std::cout << "Okay, starting new game" << std::endl;
      break;
    }
  }
  if( !open_prev )
    return new_game();
  for(int i = 0; i < saves_.size(); i++){
    std::cout << i+1 << ". : " << saves_[i] << std::endl;
  } 
  std::cout << "Which save number would you like?" << std::endl;
  input = "";
  int save_num = -1;
  while(true){
    std::cin >> input;
    if(input.find(std::string("cancel")) != std::string::npos){
      std::cout << "Canceling loading save" << std::endl;
      return new_game();
    }
    else{
      std::stringstream(input) >> save_num;
    }
    if( save_num > saves_.size() || save_num < 1){
      std::cout << "Please input a valid save number or type 'cancel'" << std::endl;
    }
    else{
      std::cout << "Loading save number " << save_num << std::endl;
      std::ifstream istrm("saves/"+saves_[save_num-1]+".dat");      
      if(istrm){
       return Env(istrm); 
      }
      else{
        std::cout << "File does not exist" << std::endl;
      }
    }
  }
}


int main(){
  std::cout << "Welcome to the NuTextBasedGame!" << std::endl;
  std::ifstream saves_istrm("saves.dat");
  std::vector<std::string> saves_(0);
  if( saves_istrm ){
    saves_istrm.close();
    saves_ = find_saves();
  }
  Env e;
  if( saves_.size() == 0)
    e = new_game();
  else
    e = previous_game(saves_);
  help();
  while(main_input_loop(e) != 1){
  }

}
