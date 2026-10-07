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

// Memoization
int lis(int i, vi& nums, vi& memo) {
    if(memo[i] != -1) return memo[i]; 
    // if (i == 0) memo[i] = 1;
    memo[i] = 1;
    if(i > 0) {
        // memo[i] = 1;
        FOR(j, 0, i) {
            if(nums[j] < nums[i])
                memo[i] = max( memo[i], lis(j, nums, memo) + 1 );
        }
    }
    return memo[i];
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { // TC: O(n^2), SC: O(n + n) // due to recursive call stack and memo[n]
        int n = nums.size();

        // vi memo(n, -1);
        // return lis(n-1, nums, memo); // Wrong logic

        // vi memo(n, -1);
        // int ans = 1;
        // FOR(i, 0, n) {
        //     ans = max(ans, lis(i, nums, memo));
        // }
        // return ans;

        //OR
        
        // Dummy Sentinel Approach
        nums.pb(INT_MAX);
        vi memo(n+1, -1);
        return lis(n, nums, memo) - 1;
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