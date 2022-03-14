// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pair<int,int> ArrPair[n];
    for(int i = 0;i<n;i++){
        ArrPair[i].first = arr[i];
         ArrPair[i].second = dep[i];
    }
    sort(ArrPair,ArrPair+n);
    pq.push(ArrPair[0].second);
    for(int i = 1; i< n ; i++){
        if(!pq.empty() && pq.top() < ArrPair[i].first){
            pq.pop();
        }
        pq.push(ArrPair[i].second);
    }
    return pq.size();
}