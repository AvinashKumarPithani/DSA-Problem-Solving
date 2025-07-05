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

// Check if each of strings in the given vector is substring of any other string in the vector.

const int P = 31;
const int Pi = 129032259;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {      // O(N*N*L); N: words.length, L: max{words[i].length}
      vs ans;
      FOR(i, 0, words.size()) {
        string s = words[i];
        bool flag = false;  
        FOR(j, 0, words.size()){          
          if(i == j) continue;
          string r = words[j]; 
          int n = r.length();
          int m = s.length();
          if(m > n) continue;
          ll hash_pattern = 0;
          ll hash_text = 0;
          ll pp = 1;
          FOR(i, 0, m) {
            hash_pattern = (hash_pattern + (s[i]-'a'+1)*pp) % MOD;
            hash_text = (hash_text + (r[i]-'a'+1)*pp) % MOD;
            pp = (pp*P) % MOD;
          }
          if(hash_text == hash_pattern) {
            flag = true;
            break;
          }
          FOR(i, m, n) {
            hash_text = (hash_text - (r[i-m]-'a'+1) + (r[i]-'a'+1)*pp) % MOD;
            hash_text = (hash_text * Pi) % MOD;
            if(hash_text == hash_pattern) {
              flag = true;
              break;
            }
          }
          if(flag) break; 
        }
        if(flag) {
          ans.pb(s);
          continue;
        }
      }
      return ans;
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