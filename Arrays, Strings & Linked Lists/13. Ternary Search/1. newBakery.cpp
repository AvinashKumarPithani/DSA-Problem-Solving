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

// https://codeforces.com/problemset/problem/1978/B

class Solution {
  public:
    ll pr(int n, int a, int b, int k) {
      return (ll)k*b - (ll)k*(k-1)/2 + (ll)(n-k)*a;
    }

    ll newBakery(int n, int a, int b) {     // O(n)
      if(b <= a) return pr(n, a, b, 0);
      ll ans = 0;
      FOR(i, 0, min(n, b)+1){
        ans = max(ans, pr(n, a, b, i));
      }
      return ans;
    }
};

void solve(Solution sol) {
    int n, a, b;
    cin >> n >> a >> b;   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // string line;
    // getline(cin, line); // Read the whole line

    // istringstream iss(line); // Create stream from line
    // vi nums;
    // int x;
    // while (iss >> x) {
    //   nums.pb(x); // Extract numbers one by one
    // }
    ll res = sol.newBakery(n, a, b);
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
