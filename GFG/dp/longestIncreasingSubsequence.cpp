// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int ans = 0;
    void solve(int s[], int m, int n, int sum, int i) {
        if (sum > n) {
            return;
        } else if (sum == n) {
            ans++;
            return;
        } else {
            for (; i < m; i++) {
                solve(s, m, n, sum + s[i], i);
            }
        }
    }
    long long int count(int S[], int m, int n) {
        solve(S, m, n, 0, 0);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++) cin >> arr[i];
    Solution ob;
    cout << ob.count(arr, m, n) << endl;

    return 0;
}

// } Driver Code Ends