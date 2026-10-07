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

// https://leetcode.com/problems/edit-distance/

class Solution {
public:
    // Memoization
    int ed(int i, int j, string &s1, string &s2, vector<vi>& memo) {   // TC: O(n*m), SC: O(n*m) + O(n+m)
        if(memo[i][j] != -1) return memo[i][j];
        
        if(i==0 || j==0) memo[i][j] = max(i, j);
        else if(s1[i-1] == s2[j-1]) {
            memo[i][j] = ed(i-1, j-1, s1, s2, memo);
        }
        else {
            memo[i][j] = 1 + min( min( ed(i-1, j, s1, s2, memo),
                                       ed(i, j-1, s1, s2, memo) ),
                                  ed(i-1, j-1, s1, s2, memo) 
                                );
        }
        return memo[i][j];

    }

    int minDistance(string &word1, string &word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vi> memo(n+1, vi(m+1, -1));

        return ed(n, m, word1, word2, memo);
    }
};

void solve(Solution sol) {
    string text1, text2;
    cin >> text1 >> text2;
    cout << sol.minDistance(text1, text2);
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