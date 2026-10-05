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

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution {
  public:
    // Tabulation
    int maxProfit(int n, vi& p) {
        
        vi dp(n+1, -1);
        dp[0] = 0;
        
        FOR(k, 1, n+1) {
            FOR(i, 1, k+1) {
                dp[k] = max( dp[k], p[i-1] + dp[k-i] );
            }
        }
        return dp[n];
    }

    int cutRod(vector<int> &price) {    // TC: O(n^2), SC: O(n)
        // code here
        int n = price.size();
        
        return maxProfit(n, price);
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
    cout << sol.cutRod(nums);
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