// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  
  int isValid(int i,int j,vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    return i<m && i>=0 && j<n && j>=0;
  }
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int,int>>q;
    int ones = 0;
    int m = grid.size();
    int n = grid[0].size();
    int time =0;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(grid[i][j]==1){
          ones++;
        }
        else if(grid[i][j]==2){
          q.push({i,j});
        }
      }
    }
    while(!q.empty()){
      int count = q.size();
      while(count--){
        auto i = q.front().first;
        auto j=q.front().second;
        q.pop();
        if(isValid(i-1,j,grid) && grid[i-1][j]==1){
          grid[i-1][j]=2;
          q.push({i-1,j});
          ones--;
        }
        if(isValid(i+1,j,grid) && grid[i+1][j]==1){
          grid[i+1][j]=2;
          q.push({i+1,j});
          ones--;
        }
        if(isValid(i,j-1,grid) && grid[i][j-1]==1){
          grid[i][j-1]=2;
          q.push({i,j-1});
          ones--;
        }
        if(isValid(i,j+1,grid) && grid[i][j+1]==1){
          grid[i][j+1]=2;
          q.push({i,j+1});
          ones--;
        }
      }
      if(!q.empty()){
        time++;
      }
    }
    if(ones){
      return -1;
    }
    return time;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  Solution obj;
  int ans = obj.orangesRotting(grid);
  cout << ans << "\n";
  return 0;
} 