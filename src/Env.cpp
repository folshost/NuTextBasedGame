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

  int get_opposite_direction(int dir) {
    if (dir == 0)
      return dir;
    if (dir < 3)
      return dir + 2;
    else
      return (dir + 3) % 5;
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
    // For ensuring new connections aren't overwriting existing connections
    std::vector<std::vector<int>> already_set(total, std::vector<int>(4, 0));
    while (count < total) {
      std::random_shuffle(rooms_left.begin(), rooms_left.end());
      // If the only room left to be connected is total-1, it may not have 
      // been connected yet, and since self-loops are disallowed, it might
      // just be orphaned
      // Maybe just do a check with the shuffle to ensure total-1 isn't
      // the last element. If each elem has >= 1 connection the last element
      // must of necessity have at most 1 connection to add.
      while (rooms_left.back() == total - 1) {
        std::random_shuffle(rooms_left.begin(), rooms_left.end());
      }
      // Ensure that no out-of-bounds accessed are made with the number of
      // neighbors
      int num_neighbors = std::rand() % (rooms_left.size()) % 4;
      std::vector<int> dir_is_used{ 0, 0, 0, 0 };
      int neighbor_list_loc = 0;
      // I suppose I could include self-loops but this would allow
      // the possibility of unreachable map areas (possibly a feature 
      // tbh[teleporting?]) but not for now
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
        // Now to point the other room back to count
        int opp_dir = get_opposite_direction(dir);
        ref_room_list[rooms_left[neighbor_list_loc]].setDir(opp_dir, count);
        already_set[rooms_left[neighbor_list_loc]][opp_dir-1] = 1;
        rooms_left.erase(rooms_left.begin() + neighbor_list_loc);
        dir_is_used[dir-1] = 1;
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
