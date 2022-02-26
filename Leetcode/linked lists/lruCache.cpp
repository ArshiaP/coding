// https://leetcode.com/problems/lru-cache/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
  unordered_map<int, int> map;
  list<int> ll;
  int cap;

  LRUCache(int capacity) {
    // map.reserve(capacity);
    cap = capacity;
  }

  int get(int key) {
    auto it = map.find(key);
    if (it == map.end()) {
      return -1;
    }
    ll.remove(key);
    ll.push_back(key);
    return (*it).second;
  }

  void put(int key, int value) {
    auto it = map.find(key);
    if (it != map.end()) {
      map[key] = value;
      ll.remove(key);
      ll.push_back(key);
    } else {
      if (map.size() == cap) {
        int x = ll.front();
        ll.pop_front();
        map.erase(x);
        map.insert(make_pair(key, value));
        ll.push_back(key);
      } else {
        map.insert(make_pair(key, value));
        ll.push_back(key);
      }
    }
  }
};