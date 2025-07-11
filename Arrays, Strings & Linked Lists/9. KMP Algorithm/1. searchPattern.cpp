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

// https://www.geeksforgeeks.org/problems/search-pattern0205/1

vi lps(string& p) {     // O(m)
    int m = p.size();
    vi l;
    l.pb(0);
    int i = 0, j = 1;
    while(j < m) {
      if(p[j] == p[i]) {
        i++;
        l.pb(i);
        j++;
      }
      else if(i==0) {
        l.pb(0);
        j++;
      }
      else {
        i = l[i-1];
      }
    }
    return l;
}

class Solution {
  public:
    vector<int> search(string& pat, string& txt) {    // O(n+m)
      // code here
      int n = txt.length();
      int m = pat.length();
      vi l = lps(pat);
      vi ans;
      int i=0;
      int j=0;
      while(i < n) {
        if(txt[i] == pat[j]) {
          i++;
          j++;
          if(j == m) {
            ans.pb(i-m);
            j = l[j-1];
          }
        }
        else if(j == 0) {
          i++;
        }
        else {
          j = l[j-1];
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