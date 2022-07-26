// https://practice.geeksforgeeks.org/problems/minimum-swaps/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSwaps(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> map;
    vector<int> copy(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]] = i;
      copy[i] = nums[i];
    }
    sort(copy.begin(),copy.end());
    for(int i = 0;i<nums.size();i++){
      if(nums[i]!=copy[i]){
        int temp = nums[i];
        int pos = map[copy[i]];
        map[nums[i]] = pos;
        map[nums[pos]] = i;
        nums[i] = nums[pos];
        nums[pos] = temp;
        ans++;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  Solution obj;
  int ans = obj.minSwaps(nums);
  cout << ans << "\n";

  return 0;
}
// } Driver Code Ends