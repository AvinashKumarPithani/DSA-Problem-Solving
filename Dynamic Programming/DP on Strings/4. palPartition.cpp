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

// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1

class Solution {
  public:
    vector<vector<bool>> substrPalCheck(string &s, int n) {
        vector<vector<bool>> p(n, vector<bool>(n));
        FOR(i, 0, n) { // len = 1
            p[i][i] = true;
        }
        
        FOR(i, 0, n-1) {// len = 2
            p[i][i+1] = s[i]==s[i+1];
        }
    
        FOR(len, 3, n+1) {
            FOR(i, 0, n-len+1) {
                int j = i+len-1;
                p[i][j] = (s[i]==s[j] && p[i+1][j-1]);
            }
        }
        return p;
    }
    
    // Memoization
    int minCuts(string &s, int i, vector<vector<bool>>& p, vi &memo) { 
        if(memo[i] != -1) return memo[i];
        if(p[0][i]) memo[i] = 0;
        else {
            memo[i] = INT_MAX;
            FOR(j, 0, i) {
                if(p[j+1][i]) {
                    memo[i] = min(memo[i], minCuts(s, j, p, memo) + 1);
                }
            }
        }
        return memo[i];
    }

    int palPartition(string &s) { // TC: O(n^2), SC: O(n^2 + n)
        // code here
        int n = s.size();
        vector<vector<bool>> p = substrPalCheck(s, n);
        vi memo(n, -1);
        return minCuts(s, n-1, p, memo);
    }
};

void solve(Solution sol) {
    string text;
    cin >> text;
    cout << sol.palPartition(text);
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