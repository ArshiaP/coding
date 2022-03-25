// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// https://leetcode.com/problems/spiral-matrix/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
  vector<int> ans;
  int row_start = 0;
  int column_start = 0;
  int row_end = r - 1;
  int column_end = c - 1;
  int count = 0;
  while (count < r * c)
  {
    for (int i = column_start; count < r * c && i <= column_end; i++)
    {
      ans.push_back(matrix[row_start][i]);
      count++;
    }
    row_start++;
    for (int i = row_start; count < r * c && i <= row_end; i++)
    {
      ans.push_back(matrix[i][column_end]);
      count++;
    }
    column_end--;

    for (int i = column_end; count < r * c && i >= column_start; i--)
    {
      ans.push_back(matrix[row_end][i]);
      count++;
    }
    row_end--;

    for (int i = row_end; count < r * c && i >= row_start; i--)
    {
      ans.push_back(matrix[i][column_start]);
      count++;
    }
    column_start++;
  }
  return ans;
}

int main()
{
  vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> arr = spirallyTraverse(mat, 3, 4);
  for (auto x : arr)
    cout << x << " ";
}