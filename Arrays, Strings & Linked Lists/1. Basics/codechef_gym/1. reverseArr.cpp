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

// https://codeforces.com/group/yg7WhsFsAp/contest/355490/problem/P01
// Given an array of integers, reverse the array and return it.

class Solution {
public:
    vi reverseArray(vector<int>& nums) {   // O(n/2) ~ O(n)
      int n = nums.size();
      int i = 0, j = n - 1;
      while(i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
      }
      return nums;
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
    vi res = sol.reverseArray(nums);
    FOR(i, 0, n) {
        cout << res[i] << " ";
    }
}

int main() {  // O(n)
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