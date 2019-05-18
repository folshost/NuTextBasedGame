#include "header/file_helper.h"

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
      Room tmp(name);
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
    for(int i = 0; i < num; i++){
      //std::cout << "Getting a Room from file!" << std::endl;
      Room tmp(istrm);
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
