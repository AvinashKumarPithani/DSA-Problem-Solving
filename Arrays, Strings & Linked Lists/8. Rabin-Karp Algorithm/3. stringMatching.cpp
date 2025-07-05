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

// https://leetcode.com/problems/string-matching-in-an-array/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {      // O(N^2 * L^2); N: words.length, L: words[i].length
        set<string> ans;
        for(int i=0; i<words.size(); i++) {
            string s = words[i];
            int n = s.length();
            for(int j=0; j<words.size(); j++) {
                string t = words[j];
                int m = t.length();
                if(j==i ||m<n) continue;
                for(int k=0; k<m-n+1; k++) {
                    int l = 0;
                    while(l < n) {
                        if(s[l] != t[k+l]) break;
                        l++;
                    }
                    if(l==n) {
                        ans.insert(s);
                        break;
                    }
                }
            }
        }
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vs words;
    string x;
    while (iss >> x) {
      words.pb(x); // Extract numbers one by one
    }
    vs res = sol.stringMatching(words);
    for(auto i: res) {
      cout << i << " ";
    }
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