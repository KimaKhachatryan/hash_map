#pragma once
#include "hash_map.h"
#include <iostream>
//helper functions

template <typename Key, typename Val>
bool hash_map<Key, Val>::is_prime (size_t size)
{
    if (size == 0 || size == 1) {
        return false;
    }

    for (size_t i = 2; i < size / 2; ++i) {
        if (size % i == 0) {
            return false;
        }
    }

    return true;
}

template <typename Key, typename Val>
size_t hash_map<Key, Val>::next_prime (size_t cur_size)
{
    if (cur_size == vec.size()) 
    {
        return cur_size;
    }

    size_t i = ++cur_size;
    for (; !is_prime (i); ++i) {
    }

    return i;
}

template <typename Key, typename Val>
size_t hash_map<Key, Val>::hashing (Key key) 
{
    return key % vec.size();
}

//main member functions

template <typename Key, typename Val>
void hash_map<Key, Val>::put (Key key, Val val)
{
    size_t index = hashing (key);
    if (vec[index].second == nullptr) {
        vec[index].second = new std::list({key, val});
        ++vec[index].first;
    } else {
        auto it = std::find(vec[index].second->begin(), vec[index].second->end(), key);
        if (it == vec[index].second->end()) {
            vec[index].second->push_front ({ key, val });
            ++vec[index].first;
        } else {
            it->second = val;
        }
    }
}

template <typename Key, typename Val>
Val hash_map<Key, Val>::get (Key key) const
{
    auto it = std::find (vec.begin (), vec.end (), key);
    if (it!= vec.end ()) {
        return it->second;
    } 
    std::cout << "Not found " << key << std::endl;
    return Val();
}


