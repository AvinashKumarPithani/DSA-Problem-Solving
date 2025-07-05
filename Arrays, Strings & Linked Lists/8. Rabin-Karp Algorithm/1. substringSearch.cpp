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

// https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=18&id_topic=42&id_problem=262

// finding all positions in string t where pattern p matches

const int P = 31;
const int Pi = 129032259;

class Solution {
  public:
    vi substringSearch(string& t, string& p) {     // O(n)
      int n = t.length();
      int m = p.length();
      if(m > n) return {-1};
      vi ans;
      ll hash_pattern = 0;
      ll hash_text = 0;
      ll pp = 1;
      FOR(i, 0, m) {
        hash_pattern = (hash_pattern + (p[i]-'a'+1)*pp) % MOD;
        hash_text = (hash_text + (t[i]-'a'+1)*pp) % MOD;
        pp = (pp*P) % MOD;
      }
      if(hash_text == hash_pattern) ans.pb(0);
      FOR(i, m, n) {
        hash_text = (hash_text - (t[i-m]-'a'+1) + (t[i]-'a'+1)*pp) % MOD;
        hash_text = (hash_text * Pi) % MOD;
        if(hash_text == hash_pattern) ans.pb(i-m+1);
      }
      if(ans.empty()) return {-1};
      return ans;
    }
};

void solve(Solution sol) {
    string t, p;
    cin >> t >> p;
    vi res = sol.substringSearch(t, p);
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