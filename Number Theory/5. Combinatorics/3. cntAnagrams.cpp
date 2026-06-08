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

// https://leetcode.com/problems/count-anagrams/

/*
You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.

A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
-- For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.

Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7. 
*/

const int MOD = 1e9+7;
const int N = 1e5;
ll f[N+1];
ll fi[N+1];

ll pow(int a, int b){   // O(log b)
  if(b == 0) return 1;
  ll ans = pow(a, b/2);
  ans = (ans*ans) % MOD;
  if(b % 2 == 1) ans = (ans*a) % MOD;
  return ans;
}


ll mod_inv(int x) {   // Fermat's little theorem: a^(p-1) ≡ 1 (mod p) for prime p and a not divisible by p
  return pow(x, MOD-2); // O(log MOD)
}

void pre_compute() {  // O(N + log MOD)
  f[0] = 1;
  FOR(i, 1, N+1) {
    f[i] = (i*f[i-1]) % MOD;
  }
  fi[N] = mod_inv(f[N]);
  rFOR(i, N-1, 0) {
    fi[i] = ((i+1)*fi[i+1]) % MOD;
  }
}

class Solution {
public:
    int countAnagrams(string s) {   // O(n)
      int ans = 1;
      int i = 0;
      int n = s.length();
      while(i < n) {
        unordered_map <char, int> mp;
        int c = 0;
        while(i < n && s[i] != ' ') {
          mp[s[i]]++;
          c++;
          i++;
        }
        ll w = f[c];
        for(auto x: mp){
          if(x.second > 1) w = (w*fi[x.second])% MOD;         
        }
        ans = (ans*w)% MOD;
        i++;
      }
      return ans;
    }
};

void solve(Solution sol) {  // O(n)
    string s;
    // cin >> s;    
    getline(cin >> ws, s); // skips the newline, reads the next line properly
    cout << sol.countAnagrams(s);
}

int main() {    // O(N + log MOD + t*n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    pre_compute();   // O(N + log MOD)
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}