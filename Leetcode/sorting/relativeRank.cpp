#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  vector<int> score{10,3,8,9,4};
  vector<string> ans(score.size(), "");
  priority_queue<int> a;
  int count=0;
  for(int x: score){
    a.push(x);
  }
  while(!a.empty()){
  count++;
  int x = a.top();
  a.pop();
  int i;
  for(i=0;i<score.size();i++){
    if(score.at(i)==x){
      break;
    }
  }
    if(count==1){
      ans.at(i) = "Gold Medal";
    }
    else if(count==2){
      ans.at(i) = "Silver Medal";
    }
    else if(count==3){
      ans.at(i) = "Bronze Medal";
    }
    else{
      ans.at(i) = to_string(count);
    }
  }


  for(string p: ans){
    cout << p << " ";
  }

}

//  priority_queue<pair<int, int>> pq;
//     int n = score.size(); 
//     for(int i = 0; i < n; i++)
//         pq.push({score[i], i});
    
//     vector<string> v(n);
//     int j = 0;
//     while(!pq.empty())
//     {
//         int idx = pq.top().second;
        
//         if(j == 0)
//             v[idx] = "Gold Medal";
//         else if(j == 1)
//             v[idx] = "Silver Medal";
//         else if(j == 2)
//             v[idx] = "Bronze Medal";
//         else
//             v[idx] = to_string(j + 1);
        
//         pq.pop(), j++;
//     }
    