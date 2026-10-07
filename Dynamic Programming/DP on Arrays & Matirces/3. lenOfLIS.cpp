#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<b; i+=k)
#define rFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define rFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vll;
typedef vector<ull> vull;

// https://leetcode.com/problems/longest-increasing-subsequence/

// Simple Recursion, We will get TLE
int lis(int i, vi& nums) {
    if (i == 0) return 1;
    int max_len = 1;
    FOR(j, 0, i) {
        if (nums[j] < nums[i]) {
            max_len = max(max_len, lis(j, nums) + 1);
        }
    }
    return max_len;
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { // TC: O(2^n), SC: O(n) //due to recursive call stack
        int n = nums.size();
        return lis(n - 1, nums);
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    // Replace '[', ']', and ',' with spaces
    for (char &ch : line) {
        if (ch == '[' || ch == ']' || ch == ',') {
            ch = ' '; // saves time rather than erasing them
        }
    }

    istringstream iss(line); // Create stream from line
    vi nums;
    ll x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    cout << sol.lengthOfLIS(nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}