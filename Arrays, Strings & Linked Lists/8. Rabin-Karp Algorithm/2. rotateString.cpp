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

// https://leetcode.com/problems/rotate-string

const int P = 31;
const int Pi = 129032259;

class Solution {
  public:
    bool rotateString(string s, string goal) {    // O(n)
      int n = s.length();
      int m = goal.length();
      if(n != m) return false;
      s += s;
      ll hash_goal = 0;
      ll hash_str = 0;
      ll pp = 1;
      FOR(i, 0, m) {
        hash_goal = (hash_goal + (goal[i]-'a'+1)*pp) % MOD;
        hash_str = (hash_str + (s[i]-'a'+1)*pp) % MOD;
        pp = (pp*P) % MOD;
      }
      if(hash_str == hash_goal) return true;
      FOR(i, m, 2*n) {
        hash_str = (hash_str - (s[i-m]-'a'+1) + (s[i]-'a'+1)*pp) % MOD;
        hash_str = (hash_str*Pi) % MOD;
        if(hash_str == hash_goal) return true;
      }
      return false;
    }
};

void solve(Solution sol) {
    string s, p;
    cin >> s >> p;
    cout << sol.rotateString(s, p);
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