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
    vector<vector<int>> threeSum(vector<int>& nums) {   // O(n^2 * log n)
      sort(nums.begin(), nums.end()); 
      int n = nums.size();
      set<vi> s;
      FOR(i, 0, n-2) {
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
            s.insert({nums[i], nums[j], nums[k]});    // O(log n)
            j++;
            k--;
          }
        }
      }
      vector<vi> ans(s.begin(), s.end());
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
    // cin >> t;
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}