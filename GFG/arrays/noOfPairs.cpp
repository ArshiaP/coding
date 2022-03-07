//https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

// If x = 0, then the count of pairs for this x is 0.
// If x = 1, then the count of pairs for this x is equal to count of 0s in Y[].
// x smaller than y means x^y is greater than y^x.
//Exceptions:
// x = 2, y = 3 or 4
// x = 3, y = 2


//ub(x) - lb(x) gives count of x in the array
long long countPairs(int X[], int Y[], int M, int N)
{
  // Your code here
  sort(Y, Y + N);
  long long int ans = 0;
  for (int i = 0; i < M; i++)
  {
    if (X[i] == 0)
    {
      continue;
    }
    else if (X[i] == 1)
    {
      ans += upper_bound(Y, Y + N, 0) - lower_bound(Y, Y + N, 0); //condn satisfied only with the 0s in Y
    }
    else
    {
      ans += upper_bound(Y, Y + N, 0) - lower_bound(Y, Y + N, 0); //0s
      ans += upper_bound(Y, Y + N, 1) - lower_bound(Y, Y + N, 1); //1s
      ans += N - (upper_bound(Y, Y + N, X[i]) - Y); //then satisfied by the number greater than X[i]. Finds the first number greater than X[i] and adds the number of elements including and after it to ans.
      if (X[i] == 2)
      {
        //3 and 4 dont satisfy
        ans -= upper_bound(Y, Y + N, 3) - lower_bound(Y, Y + N, 3); 
        ans -= upper_bound(Y, Y + N, 4) - lower_bound(Y, Y + N, 4);
      }
      else if (X[i] == 3)
      {
        //have to include 2
        ans += upper_bound(Y, Y + N, 2) - lower_bound(Y, Y + N, 2);
      }
    }
  }
  return ans;
}
