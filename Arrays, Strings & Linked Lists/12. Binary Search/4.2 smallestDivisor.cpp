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

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int bs(vi& a, int t, int l, int r) {
      if(l==r) return l;

      int mid = (l+r)/2;
      int s = 0;
      for(auto j: a) {
        s += ceil(j*1.0/mid);
      }
      if(s <= t) return bs(a, t, l, mid);
      else return bs(a, t, mid+1, r);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {     // recursive binarySearch -- O(n*log m)
      int m = *max_element(nums.begin(), nums.end());
      return bs(nums, threshold, 1, m);
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int res = sol.smallestDivisor(nums, k);
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
