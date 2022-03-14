// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// bool compare(string a, string b)
// {
//   int i = 0, j = 0;
//   while (1)
//   {
//     if (a[i] > b[j])
//     {
//       return 1;
//     }
//     else if (a[i] < b[j])
//     {
//       return 0;
//     }
//     else
//     {
//       if (i == a.size() - 1 && j == b.size() - 1)
//       {
//         return 1;
//       }
//       if (i != a.size() - 1)
//       {
//         i++;
//       }
//       if (j != b.size() - 1)
//       {
//         j++;
//       }
//     }
//   }
// }

bool compare(string a, string b)
{
  string temp1 = a + b;
  string temp2 = b + a;
  return (temp1>temp2 ? 1 : 0);
}

string printLargest(vector<string> &arr)
{
  string ans;
  sort(arr.begin(), arr.end(), compare);
  for (auto x : arr)
  {
    ans += x;
  }
  return ans;
}

int main()
{
  vector<string> arr{"15", "153"};
  string ans = printLargest(arr);
  cout << ans << endl;
}