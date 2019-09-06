#include "header/Env.h"

#include <ctime>
#include <numeric>
#include <random>

namespace detail {
  int get_random_direction() {
    int ret = std::rand() % 5;
    if (ret == 0)
      ret++;
    return ret;
  }

  // TODO allow (at least some) accidentally adjacent 
  // rooms access to each other
  void populate_map(std::vector<Room>& ref_room_list) {
    if (ref_room_list.size() == 0)
      return;
    int count = 0;
    int total = ref_room_list.size();
    std::vector<int> rooms_left(total);
    std::iota(rooms_left.begin(), rooms_left.end(), 0);
    std::vector<std::vector<int>> already_set(total, std::vector<int>(4, 0));
    while (count < total) {
      std::random_shuffle(rooms_left.begin(), rooms_left.end());
      int num_neighbors = std::rand() % (total - count) % 4;
      std::vector<int> dir_is_used{ 0, 0, 0, 0 };
      int neighbor_list_loc = 0;
      // I suppose I could include self-loops but this would allow
      // the possibility of unreachable map areas (possibly a feature tbh)
      // but not for now
      // TODO - Make sure that if a forward/backward reference pair has been 
      // established that a new one doesn't overwrite it. I could do that with
      // a matrix of Nx4 bools (where N = num of rooms)
      for (int i = 0; i < num_neighbors; i++) {
        int dir = get_random_direction();
        while (dir_is_used[dir-1]) {
          dir = get_random_direction();
        }
        if (rooms_left[neighbor_list_loc] == count)
          neighbor_list_loc++;
        if (already_set[count][dir-1])
          continue;
        // Set the forward reference
        ref_room_list[count].setDir(dir, rooms_left[neighbor_list_loc]);
        already_set[count][dir-1] = 1;
        // TODO - Might be interesting to look at making some transitions one-way
        // Point the other room back to count
        // TODO - Fix the mess I made by needing to introduce a null direction index value
        ref_room_list[rooms_left[neighbor_list_loc]].setDir((dir + 2) % 4, count);
        already_set[rooms_left[neighbor_list_loc]][(dir + 2) % 4] = 1;
        rooms_left.erase(rooms_left.begin() + neighbor_list_loc);
        dir_is_used[dir] = 1;
      }
      count++;
    }
  }
}

Env::Env() : pc_(Player("null")), rooms_(std::vector<Room>()), loc_(0){}

Env::Env(Player& p) : pc_(p), rooms_(std::vector<Room>()), loc_(0) {
}

Env::Env(std::vector<Room>& r, Player& p) : pc_(p), rooms_(r), loc_(0) {
  std::srand(std::time(nullptr));
  int root_room = std::rand() % r.size();
  detail::populate_map(rooms_);
}

Env::Env(std::ifstream& istrm) : pc_(Player(istrm)), rooms_(std::vector<Room>()), loc_(0) { }

std::string Env::get_char_name(){ 
  return pc_.get_name(); 
}

Room& Env::get_current_room(){ return rooms_.at(loc_); }

Player& Env::get_pc(){ return pc_; }
