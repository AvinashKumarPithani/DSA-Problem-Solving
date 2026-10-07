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
    // Tabulation
    int minDistance(string &s1, string &s2) { // TC: O(n*m), SC: O(m)
        int n = s1.size();
        int m = s2.size();
        // vector<vi> dp(n+1, vi(m+1, 0));
        vi prev(m+1);
        vi curr(m+1);

        FOR(i, 0, m+1) {
            prev[i] = i;
            // curr[i] = i;
        }

        FOR(i, 1, n+1) {
            curr[0] = i;
            FOR(j, 1, m+1) {
                // if(i == 0 || j == 0) {
                //     d[i][j] = max(i, j);  
                // }
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = prev[j-1];
                }
                else {
                    curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
                }
            }
            prev = curr;
        }
        
        return prev[m];
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