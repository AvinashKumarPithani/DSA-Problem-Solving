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
const int MOD = 1e9+7;

class Solution {
public:
    int missingNumber(vector<int>& nums) {    // O(n^2)
      int n = nums.size();
      FOR(i, 0, n+1) {
        bool flag = false;
        FOR(j, 0, n) {
          if(nums[j] == i) {
            flag = true;
            break;
          }
        }
        if(flag == false) {
          return i;
        }
      }
    }
};

void solve(Solution sol) {
    vi nums;
    FOR(i, 0, nums.size()){
      int x;
      cin >> x;
      nums.pb(x);
    }
    cout << sol.missingNumber(nums);
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