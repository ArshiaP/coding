//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1#
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//better approach - after k elements are inserted, check if the incoming element is smaller than the top element. if it is just print the top element, else pop the top element and insert the new element, push the top element into the ans array.
class Solution {
 public:
  vector<int> kthLargest(int k, int arr[], int n) {
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int> ans;
    for(int i=0;i<n;i++){
      pq.push(arr[i]);
      if(pq.size()<k){
        ans.push_back(-1);
      }
      else if(pq.size()==k){
        ans.push_back(pq.top());
      }
      else{
        pq.pop();
        ans.push_back(pq.top());
      }
    }
    return ans;
  }

  //better approach implementation
  vector<int> kthLargest(int k, int arr[], int n) {
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int> ans;
    int i;
    for(i=0;i<k-1;i++){
      pq.push(arr[i]);
      ans.push_back(-1);
    }
    pq.push(arr[i]);
    i++;
    ans.push_back(pq.top());
    for(;i<n;i++){
      if(arr[i]>pq.top()){
        pq.pop();
        pq.push(arr[i]);
        ans.push_back(pq.top());
      }
      else{
        ans.push_back(pq.top());
      }
    }
    return ans;
  }
};

int main() {
  int k, n;
  cin >> k >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  Solution ob;
  vector<int> v = ob.kthLargest(k, arr, n);
  for (int i : v)
    cout << i << " ";
  cout << endl;
  return 0;
}  // } Driver Code Ends