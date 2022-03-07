//https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverseInGroups(vector<long long>& arr, int n, int k) {
  for (int i = 0; i < n; i += k) {
    int a;
    int b;
    int temp;
    if (i + k - 1 >= n) {
      b = n - 1;
    } else {
      b = i + k - 1;
    }
    a = i;
    while (a < b) {
      temp = arr[a];
      arr[a] = arr[b];
      arr[b] = temp;
      a++;
      b--;
    }
  }
}

int main() {
  vector<long long> arr{1, 2, 3, 4, 5};
  reverseInGroups(arr, 5, 3);
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << endl;
  }
}