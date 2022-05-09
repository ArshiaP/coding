// https://practice.geeksforgeeks.org/problems/circular-tour/1#
#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
  int petrol;
  int distance;
};

class Solution {
 public:
  int tour(petrolPump p[], int n) {
    int start = 0;
    int total = 0;
    int diff = 0;
    for (int i = 0; i < n; i++) {
      total += p[i].petrol - p[i].distance;
      if (total < 0) {
        diff += total;
        total = 0;
        start = i + 1;
      }
    }
    if (total + diff < 0) {
      return -1;
    }
    return start;
  }
};

int main() {
  int n;
  cin >> n;
  petrolPump p[n];
  for (int i = 0; i < n; i++)
    cin >> p[i].petrol >> p[i].distance;
  Solution obj;
  cout << obj.tour(p, n) << endl;
}