//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = nums[k-1] - nums[0];
        for(int i=1;i<nums.size()-k+1;i++){
            res= min(res, nums[i+k-1] - nums[i]);
        }
        return res;
    }
};

int main(){
    vector<int>v{90};
    int k = 1;
    Solution s;
    cout << s.minimumDifference(v,k);
}