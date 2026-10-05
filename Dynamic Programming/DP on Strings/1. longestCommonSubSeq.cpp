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

// https://leetcode.com/problems/longest-common-subsequence/submissions/2163056269/

class Solution {
public:
    // Memoization
    int lcs(string& x, string& y, int i, int j, vector<vi>& memo) {
        if(memo[i][j] != -1) return memo[i][j];

        if(i==0 || j==0) memo[i][j] = 0;
        else if(x[i-1]==y[j-1]) memo[i][j] = 1 + lcs(x, y, i-1, j-1, memo);
        else memo[i][j] = max(lcs(x, y, i, j-1, memo), lcs(x, y, i-1, j, memo));

        return memo[i][j];
    }
    int longestCommonSubsequence(string &text1, string &text2) {  // TC: O(n*m), SC: O(n*m)
        int n = text1.size();
        int m = text2.size();
        vector<vi> memo(n+1, vi(m+1, -1));
        return lcs(text1, text2, n, m, memo);
    }
};

void solve(Solution sol) {
    string text1, text2;
    cin >> text1 >> text2;
    cout << sol.longestCommonSubsequence(text1, text2);
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