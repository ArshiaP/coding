//https://leetcode.com/problems/design-twitter/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Twitter {
public:

    unordered_map<int,unordered_set<int>> map;
    vector<pair<int,int>> tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(make_pair(userId,tweetId));
        auto it = map.find(userId);
        if(it== map.end()){
          map[userId] = {};
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        auto it = map.find(userId);
        vector<int> result;
        int counter =0;
        for(auto i=tweets.rbegin(); i!= tweets.rend();i++){
          if(((*i).first==userId || (*it).second.count((*i).first))&&counter<10){
            result.push_back((*i).second);
            counter++;
          }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
       auto it = map.find(followerId);
       if(it!= map.end()){
         (*it).second.insert(followeeId);
       }
       else{
         map[followerId] = {followeeId};
       }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = map.find(followerId);
        if((*it).second.count(followeeId)){
          (*it).second.erase(followeeId);
        }
    }
};
