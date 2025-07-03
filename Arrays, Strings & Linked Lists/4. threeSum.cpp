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
    vector<vector<int>> threeSum(vector<int>& nums) {  // O(n^2 * log n)
      int n = nums.size();
      set<vi> ans;
      FOR(k, 0, n) {
        int target = -nums[k];
        int i;
        unordered_set<int> m;
        FOR(i, k+1, n) {
          if(m.find(target-nums[i]) != m.end()) {
            vi v = {nums[k], nums[i], target-nums[i]};
            sort(v.begin(), v.end());
            ans.insert(v);
          }
          m.insert(nums[i]);
        }
      }
      vector<vi> res(ans.begin(), ans.end());
      return res;
    }
};

void solve(Solution sol) {
    vi nums;
    FOR(i, 0, nums.size()){
      int x;
      cin >> x;
      nums.pb(x);
    }
    vector<vi> res = sol.threeSum(nums);
    for(auto i: res) {
      for(auto j: i) {
        cout << j << " ";
      }
      cout << '\n';
    }
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