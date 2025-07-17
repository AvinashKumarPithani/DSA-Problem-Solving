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

// https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1

class Solution {
  public:
    int minDaysBloom(int m, int k, vector<int> &arr) {    // O(n*m) | m: maxi, n: arr.length()
      if(m*k > arr.size()) return -1;
      
      int maxi = *max_element(arr.begin(), arr.end());
      int mini = *min_element(arr.begin(), arr.end());
      FOR(x, mini, maxi) {
        int mc = 0, ans = 0;
        for(auto i: arr) {
          if(i <= x) mc++;
          else mc = 0;
          if(mc == k) {
            ans++;
            mc = 0;
          }
          if(ans == m) {
            return x;
          }
        }
      }
    }
};

void solve(Solution sol) {
    int m, k;
    cin >> m >> k;   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vi nums;
    int x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    int res = sol.minDaysBloom(m , k, nums);
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
