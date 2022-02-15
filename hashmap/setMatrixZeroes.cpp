// https://leetcode.com/problems/set-matrix-zeroes/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
  vector<vector<int>> matrix{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<pair<int, int>> v;

  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      if (matrix[i][j] == 0)
      {
        v.push_back({i, j});
      }
    }
  }

  for (int i = 0; i < v.size(); i++)
  {

    int row = v[i].first;
    int col = v[i].second;

    for (int j = row; j >= 0; j--)
    {
      matrix[j][col] = 0;
    }

    for (int j = row; j < matrix.size(); j++)
    {
      matrix[j][col] = 0;
    }

    for (int j = col; j >= 0; j--)
    {
      matrix[row][j] = 0;
    }

    for (int j = col; j < matrix[0].size(); j++)
    {
      matrix[row][j] = 0;
    }
  }
  for (int i = 0; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[i].size(); j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

//less memory space
int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

  int firstRowZero = 0;
  int firstColZero = 0;

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0; //markers indicating that that row or column must be 0
        matrix[i][0] = 0;
        if (i == 0)
          firstRowZero = 1;
        if (j == 0)
          firstColZero = 1;
      }
    }
  }

  // rows (starting from 1 because 0th row or column will always have a 0 due to the previous for loop)
  for (int i = 1; i < matrix.size(); i++) {
    if (matrix[i][0] == 0) {
      for (int j = 0; j < matrix[0].size(); j++) {
        matrix[i][j] = 0;
      }
    }
  }

  // cols
  for (int i = 1; i < matrix[0].size(); i++) {
    if (matrix[0][i] == 0) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[j][i] = 0;
      }
    }
  }

  if (firstRowZero) {
    for (int i = 0; i < matrix[0].size(); i++) {
      matrix[0][i] = 0;
    }
  }
  if (firstColZero) {
    for (int i = 0; i < matrix.size(); i++) {
      matrix[i][0] = 0;
    }
  }

  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}