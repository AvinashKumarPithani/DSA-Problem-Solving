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

// https://leetcode.com/problems/sort-array-by-parity/
// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers. Return any array that satisfies this condition.

class Solution {
  public:
    vector<int> sortArrayByParity(vector<int> &nums) {  // O(n)
        int l, h;
        l = 0;
        h = nums.size()-1;
        while(l < h) {
          if((nums[l]&1) == 0) {
            l++;
          }
          else{
            swap(nums[l], nums[h]);
            h--;
          }
        }
        return nums;
    }
};

void solve(Solution sol) {  // O(n)
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vi nums;
    int x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    nums = sol.sortArrayByParity(nums);
    for(auto i: nums) {
      cout << i << " ";
    }    
}

int main() {  // O(t*n)
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