#include "header/file_helper.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>


std::vector<Item> get_items(){
  std::string file_name = "items.dat";
  std::ifstream istrm(file_name);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << file_name << '\n';
  } 
  else {
    std::vector<Item> ret;
    while(true){
      Item tmp(istrm);
      ret.push_back(tmp);
      if( istrm.bad() || istrm.fail() )
        throw std::runtime_error("Parsing " + file_name + " failed");
      if( istrm.eof() )
        break;
    }
    return ret;
  }
  return std::vector<Item>();  
 
}

std::vector<Room> get_raw_rooms(){
  //std::cout << "Getting rooms!" << std::endl;
  std::string file_name = "rooms_.dat";
  std::ifstream istrm(file_name);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << file_name << '\n';
  } 
  else {
    std::vector<Room> ret;
    int num = 0;
    istrm >> num;
    for(int i = 0; i < num; i++){
      //std::cout << "Getting a Room from file!" << std::endl;
      std::string name = "";
      istrm >> name;
      Room tmp(name, std::vector<Item>());
      //std::cout << "Got a room from file!" << std::endl;
      ret.push_back(tmp);
      if( istrm.bad() || istrm.fail() )
        throw std::runtime_error("Parsing " + file_name + " failed");
      else if( istrm.eof() )
        break;
    }
    return ret;
  }
  return std::vector<Room>();  

}

std::vector<Room> get_rooms(){
  //std::cout << "Getting rooms!" << std::endl;
  std::string file_name = "rooms.dat";
  std::ifstream istrm(file_name);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << file_name << '\n';
  }
  else {
    std::vector<Room> ret;
    int num = 0;
    istrm >> num;
    for (int i = 0; i < num; i++) {
      //std::cout << "Getting a Room from file!" << std::endl;
      std::string room_name = "";
      // Number of items is a feature of the room, the items themselves are not, for now
      int num_items;
      istrm >> room_name;
      // Input file can't have white space
      std::replace(room_name.begin(), room_name.end(), '_', ' ');
      istrm >> num_items;
      std::vector<Item> items;
      for (int j = 0; j < num_items; j++) {
        items.push_back(Item(istrm));
      }
      Room tmp = Room(room_name, items);
      //std::cout << "Got a room from file!" << std::endl;
      ret.push_back(tmp);
      if (istrm.bad() || istrm.fail())
        throw std::runtime_error("Parsing " + file_name + " failed");
      else if (istrm.eof())
        break;
    }
    return ret;
  }
  return std::vector<Room>();
}

/*
std::vector<Room> get_rooms_from_save(){
  std::string file_name = "save_rooms.dat";
  std::ifstream istrm(file_name);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << file_name << '\n';
  } 
  else {
    std::vector<Room> ret;
    for( Room tmp; tmp(istrm) ; ){
      ret.push_back(tmp);
    }
    return ret;
  }
  return std::vector<Room>();  
}
*/
std::vector<std::string> find_saves(){
  std::string file_name = "saves.dat";
  std::ifstream istrm(file_name);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << file_name << '\n';
  } 
  else {
    std::vector<std::string> ret;
    int num = 0;
    istrm >> num;
    for(int i = 0; i < num; i++){
      //std::cout << "Getting a Room from file!" << std::endl;
      std::string save_name;
      istrm >> save_name;
      //std::cout << "Got a room from file!" << std::endl;
      ret.push_back(save_name);
      if( istrm.bad() || istrm.fail() )
        throw std::runtime_error("Parsing " + file_name + " failed");
      else if( istrm.eof() )
        break;
    }
    return ret;
  }
  return std::vector<std::string>();  
 
}
