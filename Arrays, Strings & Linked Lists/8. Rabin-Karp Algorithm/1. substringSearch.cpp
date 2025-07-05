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

const int P = 31;

class Solution {
  public:
    ll substringSearch(string& s) {     // O(n^2)
      int n = s.length();
      set<ll> ans;
      FOR(i, 0, n) {
        int last_hash = 0;
        ll pp = 1;
        FOR(j, i, n) {
          last_hash = (last_hash + (s[j]-'a'+1)*pp) % MOD;
          ans.insert(last_hash);
          pp = (pp*P) % MOD;
        }
      }
      return ans.size();
    }
};

void solve(Solution sol) {
    string s, p;
    cin >> s >> p;
    cout << sol.number_of_unique_substrings(s);
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