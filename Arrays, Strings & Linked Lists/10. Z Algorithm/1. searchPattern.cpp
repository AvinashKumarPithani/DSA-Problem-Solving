#include <bits/stdc++.h>
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

// https://www.geeksforgeeks.org/problems/search-pattern-z-algorithm--141631/1

// search the positions of the pat in the txt of 1-indexed

class Solution {
  public:
    vector<int> calc_z(string& s) {    // O(slen)
      int slen = s.length();
      vector<int> z(slen, 0);
      int L = 0, R = 0;
      FOR(i, 1, slen) {
        if(i > R) {
          L = R = i;
          while(R < slen && s[R-L] == s[R]) {
            R++;
          }
          z[i] = R-L;
          R--;
        }
        else if(i+z[i-L] <= R) {
          z[i] = z[i-L];
        }
        else {
          L = i;
          R++;
          while(R < slen && s[R-L] == s[R]) {
            R++;
          }
          z[i] = R-L;
          R--;
        }
      }
      return z;
    }
    vector<int> search(string& pat, string& txt) {    // TC: O(n+m), SC: O(n+m)
      string s = pat + '#' + txt;
      int slen = s.length();
      int m = pat.length();
      vector<int> z = calc_z(s);
      vector<int> ans;
      FOR(i, 0, slen) {
        if(z[i] == m) {
          ans.pb(i-m);
        }
      }
      return ans;
    }
};

void solve(Solution sol) {
    string t, p;
    cin >> t >> p;
    vi res = sol.search(p, t);
    for(auto i: res) {
      cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}