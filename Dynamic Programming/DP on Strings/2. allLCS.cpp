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
typedef vector<bool> vb;
const int MOD = 1e9+7;

// https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

class Solution {
public:

    void backtrack(string &x, string &y, int i, int j, vector<vi> &dp, string &lcs, set<string> &res) {
        if(i==0 || j==0) {
            res.insert(lcs);
            return;
        }
        if(x[i-1] == y[j-1]) {
            lcs = x[i-1] + lcs;
            backtrack(x, y, i-1, j-1, dp, lcs, res);
            lcs.erase(0, 1);
        } 
        else {
            if(dp[i-1][j] > dp[i][j-1]) backtrack(x, y, i-1, j, dp, lcs, res);
            else if(dp[i][j-1] > dp[i-1][j]) backtrack(x, y, i, j-1, dp, lcs, res);
            else {
                backtrack(x, y, i-1, j, dp, lcs, res);
                backtrack(x, y, i, j-1, dp, lcs, res);
            }
            
        }
    }

    // Tabulation
    vector<string> allLCS(string &x, string &y) {   // Got TLE, Test Cases Passed: 40 /50
        // TC: O(n*m) for DP + exponential backtracking in the worst case
        // SC: O(n*m + k*l), excluding recursion stack
        // where k = number of distinct LCSs and l = length of each LCS
        int n = x.size();
        int m = y.size();
        vector<vi> dp(n+1, vi(m+1, 0));
        FOR(i, 1, n+1) {
            FOR(j, 1, m+1) {
                if(x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        set<string> res;
        string lcs = "";
        backtrack(x, y, n, m, dp, lcs, res);

        return vector<string>(res.begin(), res.end());
    }
};

void solve(Solution sol) {
    string text1, text2;
    cin >> text1 >> text2;
    vector<string> result = sol.allLCS(text1, text2);
    for(const string& s : result) {
        cout << s << " ";
    }
    cout << endl;
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