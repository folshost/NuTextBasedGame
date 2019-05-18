#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include "Room.h"
#include "Item.h"

#include <string>

std::vector<Item> get_items();

std::vector<Room> get_rooms();

std::vector<std::string> find_saves();

#endif
