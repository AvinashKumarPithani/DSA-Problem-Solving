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

// https://leetcode.com/problems/largest-number/


class Solution {
public:
    string largestNumber(vector<int>& nums) {   // O(m*n*log n) | m : max(v[i].length), n : nums.size
      vector<string> v;
      for(auto i: nums) {
        v.pb(to_string(i));
      }
      sort(v.begin(), v.end(), [](string &a, string &b) {
        return (a + b) > (b + a);
      });
      
      if(v[0] == "0") return "0";
      string s = "";
      for(auto i: v) {
        s += i;
      }

      // if(s[0] == '0') return "0";
      return s;
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vi nums;
    int x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    // int k;
    // cin >> k;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string res = sol.largestNumber(nums);
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
