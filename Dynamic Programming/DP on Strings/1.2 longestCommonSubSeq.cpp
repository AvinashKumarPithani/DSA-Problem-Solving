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
    // Tabulation
    int longestCommonSubsequence(string &x, string &y) {  // TC: O(n*m), SC: O(min(n, m))
        int n = x.size();
        int m = y.size();

        if(n < m) return longestCommonSubsequence(x, y);

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        FOR(i, 1, n+1) {
            FOR(j, 1, m+1) {
                if(x[i-1] == y[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
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