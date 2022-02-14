#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>


using namespace std;

int main(){
  vector<int>tickets = {5,1,1,1};
  int time;
  int k=0;
  for(int i=0;i<k+1;i++){
    if(tickets[i]<=tickets[k]){
      time += tickets[i];
    }
    else{
      time += tickets[k];
    }
  }
  for(int i = k+1;i<tickets.size();i++){
    if(tickets[i]<=tickets[k]){
      time += tickets[i];
    }
    else{
      time += tickets[k]-1;
    }
  }
  cout << time;
}

//Shreyas' solution

// int main() {
//   vector<int> tickets{5, 1, 1, 1};
//   int k = 0;

//   int time = 0;
//   queue<pair<int, int>> qu;
//   for (int i = 0; i < tickets.size(); i++) {
//     qu.push(make_pair(i, tickets[i]));
//   }

//   while (!(qu.front().first == k && qu.front().second == 1)) {
//     qu.front().second--;
//     time++;
//     auto x = qu.front();
//     if (x.second != 0) {
//       qu.push(x);
//     }
//     qu.pop();
//   }
//   time++;

//   cout << time << endl;
// }