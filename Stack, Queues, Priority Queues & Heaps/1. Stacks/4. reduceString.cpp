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

// https://www.geeksforgeeks.org/problems/restrictive-candy-crush--141631/1

// reduce string by choosing k consecutive identical characters and remove them

class Solution {
  public:
    string Reduced_String(int k, string s) {    // O(n)
      if(k == 1) return "";
      stack<pair<char,int>> st;
      for(auto &i: s) {
        if(!st.empty() && i == st.top().first) {
          st.top().second++;
          if(st.top().second == k) {
            st.pop();
          }
        }
        else {
          st.push({i, 1});
        }
      }
      string ans = "";
      while(!st.empty()) {
        int c = st.top().second;
        while(c--) {
          // ans = st.top().first + ans;
          ans += st.top().first;
        }
        st.pop();
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};

void solve(Solution sol) {
    int k;
    cin >> k;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    // getline(cin, line); // Read the whole line

    // istringstream iss(line); // Create stream from line
    // vi nums;
    // int x;
    // while (iss >> x) {
    //   nums.pb(x); // Extract numbers one by one
    // }
    cin >> line;
    string res = sol.Reduced_String(k, line);
    cout << res;
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
