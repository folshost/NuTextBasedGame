#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include "Room.h"
#include "Item.h"

#include <string>
#include <memory>

std::vector<Item> get_items();

std::shared_ptr<Room> get_root_room();

std::vector<std::string> find_saves();

#endif
