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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {   // O(n^2)
      sort(nums.begin(), nums.end()); 
      int n = nums.size();
      vector<vi> ans;
      int i=0;
      while(i<n-2) {
        int j = i+1;
        int k = n-1;
        int target = - nums[i];
        while(j < k) {
          if(nums[j] + nums[k] > target) {
            k--;
          }
          else if(nums[j] + nums[k] < target) {
            j++;
          }
          else {
            ans.pb({nums[i], nums[j], nums[k]});
            j++;
            k--;
            while(j<k && nums[j]==nums[j-1]) j++;
            while(j<k && nums[k]==nums[k+1]) k--;
          }
        }
        i++;
        while(i<n-2 && nums[i]==nums[i-1]) i++;
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