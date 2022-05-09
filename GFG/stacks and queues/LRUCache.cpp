// https://practice.geeksforgeeks.org/problems/lru-cache/1#

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
 private:
  list<int> mylist; //keeps track of the order
  unordered_map<int, pair<int, list<int>::iterator>> map; //key,{value, position in dll}
  int capacity;

 public:
  // Constructor for initializing the cache capacity with the given value.
  LRUCache(int cap) {
    // code here
    capacity = cap;
  }

  // Function to return value corresponding to the key.
  int get(int key) {
    // your code here
    if(map.find(key)==map.end()){
      return -1;
    }
    mylist.erase(map[key].second);
    mylist.push_back(key);
    auto it = mylist.end();
    it--;
    map[key].second = it;
    return map[key].first;
  }

  // Function for storing key-value pair.
  void set(int key, int value) {
    // your code here
    if (map.size() == capacity && map.find(key) == map.end()) {
      int x = mylist.front();
      map.erase(x);
      mylist.push_back(key);
      mylist.erase(mylist.begin());
      auto it = mylist.end();
      it--;
      map.insert({key, make_pair(value, it)});
      return;
    }
    if (map.find(key) == map.end() && map.size() != capacity) {
      mylist.push_back(key);
      auto it = mylist.end();
      it--;
      map.insert({key, make_pair(value, it)});
      return;
    }
    pair<int,list<int>::iterator> temp = map[key];
    mylist.erase(temp.second);
    mylist.push_back(key);
    auto it = mylist.end();
    it--;
    temp.second = it;
    temp.first = value;
    map[key] = temp;
    return;
  }
};

// { Driver Code Starts.

int main() {
  int capacity;
  cin >> capacity;
  LRUCache *cache = new LRUCache(capacity);

  int queries;
  cin >> queries;
  while (queries--) {
    string q;
    cin >> q;
    if (q == "SET") {
      int key;
      cin >> key;
      int value;
      cin >> value;
      cache->set(key, value);
    } else {
      int key;
      cin >> key;
      cout << cache->get(key) << " ";
    }
  }
  cout << endl;
  return 0;
}