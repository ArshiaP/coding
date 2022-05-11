//https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#
#include <bits/stdc++.h>
using namespace std;

//pop from the back of the deque till curr ele>q.back(). if q.front() is outside the window, pop. Push the curr ele. 
//this removes useless elements of the window and keeps only what could be the maximum element in that window
class Solution {
 public:
  vector<int> max_of_subarrays(int *arr, int n, int k) {
    deque<int>q;
    int i;
    vector<int>ans;
    for(i=0;i<k;i++){
      while(!q.empty() && arr[q.back()]<arr[i]){
        q.pop_back();
      }
      q.push_back(i);
    }
    ans.push_back(arr[q.front()]);
    for(i=k;i<n;i++){
      while(!q.empty() && q.front()<=i-k){
        q.pop_front();
      }
      while(!q.empty() && arr[q.back()]<arr[i]){
        q.pop_back();
      }
      q.push_back(i);
      ans.push_back(arr[q.front()]);
    }
    return ans;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  Solution ob;
  vector<int> res = ob.max_of_subarrays(arr, n, k);
  for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}