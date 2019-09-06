#ifndef HELPER_H
#define HELPER_H

#include "Env.h"
#include "Item.h"

#include <iostream>
#include <vector>

void get_item(Env e);

void go(Env& e, std::string i);

void help();

void look(Env& k);

void ls(Env& k);

void inv(Env& k);

int ascend(int level);
#endif
