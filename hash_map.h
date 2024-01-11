#pragma once
#include <vector>
#include <list>
#include <utility>

template <typename Key, typename Val>
class hash_map {
  std::vector<std::pair<size_t, std::list<std::pair<Key, Val> >* > > vec;

//helper functions
  bool is_prime(size_t size);
  size_t next_prime(size_t cur_size);
  size_t hashing(Key key);

public:
  hash_map() : vec(7) {}
  hash_map(size_t size) : vec(is_prime(size) ? size : next_prime(size)) {};

  void put(Key key, Val val);
  Val get(Key key) const;
};
#include "hash_map.hpp"