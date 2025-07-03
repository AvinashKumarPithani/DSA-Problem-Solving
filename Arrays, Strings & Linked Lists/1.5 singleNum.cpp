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

class Solution {
public:
    int singleNumber(vector<int>& nums) {   // O(n)
      int ans = 0;
      for(auto i: nums) {
        ans ^= i;
      }
      return ans;
    }
};

void solve(Solution sol) {
    vi nums;
    FOR(i, 0, nums.size()){
      int x;
      cin >> x;
      nums.pb(x);
    }
    cout << sol.singleNumber(nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}