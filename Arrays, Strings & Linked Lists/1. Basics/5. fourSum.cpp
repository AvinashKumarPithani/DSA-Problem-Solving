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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {   // O(n^3)
      sort(nums.begin(), nums.end()); 
      int n = nums.size();
      vector<vi> ans;
      int i=0;
      while(i<n-3) {
        int j = i+1;
        while(j<n-2) {
          int k = j+1;
          int l = n-1;
          while(k<l) {
            ll sum = (ll)nums[i] + nums[j] + nums[k] + nums[l];
            if(sum > target) l--;
            else if(sum < target) k++;
            else {
              ans.pb({nums[i], nums[j], nums[k], nums[l]});
              k++;
              l--;
              while(k<l && nums[k]==nums[k-1]) k++;
              while(k<l && nums[l]==nums[l+1]) l--;
            }
          }
          j++;
          while(j<n-2 && nums[j]==nums[j-1]) j++;
        }
        i++;
        while(i<n-3 && nums[i]==nums[i-1]) i++;
      }     
      return ans;
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
    int k;
    cin >> k;
    vector<vi> res = sol.fourSum(nums, k);
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
    // cin >> t;
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}