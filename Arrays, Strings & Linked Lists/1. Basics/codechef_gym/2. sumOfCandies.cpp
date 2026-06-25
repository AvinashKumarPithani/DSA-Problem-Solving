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

// https://codeforces.com/group/yg7WhsFsAp/contest/355490/problem/P02
// Given an array of integers and two indices l and r, return the sum of the elements from index l to r (inclusive).

class Solution {
public:
    int sumOfCandies(vector<int>& nums, int l, int r) {  // O(n)
      int n = nums.size();
      int sum = 0;
      for (int i = l; i <= r; i++) {
        sum += nums[i];
      }
      return sum;   
    }
};

void solve(Solution sol) {  // O(n)
    // string line;
    // getline(cin, line); // Read the whole line

    // istringstream iss(line); // Create stream from line
    // vi nums;
    // int x;
    // while (iss >> x) {
    //   nums.pb(x); // Extract numbers one by one
    // }
    int n;
    cin >> n;
    vi nums(n);
    FOR(i, 0, n) cin >> nums[i];
    int l, r;
    cin >> l >> r;
    int res = sol.sumOfCandies(nums, l, r);
    cout << res;
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