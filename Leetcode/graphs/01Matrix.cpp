// https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int n;
  int m;
  bool isValid(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
  }
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    n = mat.size();
    m = mat[0].size();
    vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(), INT_MAX));
    queue<pair<int, int>> q;
    vector<vector<int>>change{{-1,0},{1,0},{0,-1},{0,1}};
    for (int i = 0; i < mat.size(); i++) {
      for (int j = 0; j < mat[0].size(); j++) {
        if (mat[i][j] == 0) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
      while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
          int newI = i+change[k][0];
          int newJ = j+change[k][1];
          if(isValid(newI,newJ)){
            if(dist[i][j]+1 < dist[newI][newJ]){
              dist[newI][newJ] = dist[i][j]+1;
              q.push({newI,newJ});
            }
          }
        }
      }
    }
    return dist;
  }
};


//dp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};


int main(){
  vector<vector<int>>mat{{0},{0},{0},{0},{0}};
  //vector<vector<int>>mat{{0,0,0},{0,1,0},{0,0,0}};
  Solution ob;
  vector<vector<int>>ans = ob.updateMatrix(mat);
  for(auto x: ans){
    for(auto y: x){
      cout<<y<<" ";
    }
    cout<<endl;
  }
}