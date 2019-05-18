#ifndef HELPER_H
#define HELPER_H

#include "Env.h"
#include "Item.h"

#include <iostream>
#include <vector>

void get_item(Env e);

void help();

void look(std::vector<Item> k);

void ls(std::vector<Item> k);

void inv(std::vector<Item> k);

int ascend(int level);
#endif
