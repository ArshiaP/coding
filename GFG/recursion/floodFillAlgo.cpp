//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:

  void traverse(vector<vector<int>>& image,int newColor,int og, int sr, int sc){
    if(sr<0|| sc<0 || sr>image.size()-1 || sc>image[0].size()-1){
      return;
    }
    if(image[sr][sc] == og){
      image[sr][sc] = -1;
      traverse(image,newColor,og,sr-1,sc);
      traverse(image,newColor,og,sr+1,sc);
      traverse(image,newColor,og,sr,sc-1);
      traverse(image,newColor,og,sr,sc+1);
    }
  }

  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
   int og  = image[sr][sc];
   traverse(image,newColor,og,sr,sc);
   for(int i = 0;i<image.size();i++){
    for(int j=0;j<image[0].size();j++){
      if(image[i][j]==-1){
        image[i][j] = newColor;
      }
    }
   }
   return image;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> image(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> image[i][j];
  }
  int sr, sc, newColor;
  cin >> sr >> sc >> newColor;
  Solution obj;
  vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
  for (auto i : ans) {
    for (auto j : i)
      cout << j << " ";
    cout << "\n";
  }
  return 0;
}  // } Driver Code Ends