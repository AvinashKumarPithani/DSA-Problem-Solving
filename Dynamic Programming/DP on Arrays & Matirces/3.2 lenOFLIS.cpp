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

class Solution {
public:
    // Tabulation
    int lengthOfLIS(vector<int>& nums) { // TC: O(n^2), SC: O(n)
        int n = nums.size();
        vi dp(n, 1);
        FOR(i, 1, n) {
            FOR(j, 0, i) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
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