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

// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {   // O(n)
      int n = ratings.size();
      vi d(n, 1);
      FOR(i, 1, n) {
        if(ratings[i] > ratings[i-1]) {
          d[i] = d[i-1] + 1;
        }
      }
      rFOR(i, n-2, 0) {
        if(ratings[i] > ratings[i+1] && d[i] <= d[i+1]) {
          d[i] = d[i+1] + 1;
        }
      }
      int minCandies = 0;
      for(auto i: d) {
        minCandies += i;
      }
      return minCandies;
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
    int res = sol.candy(nums);
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
