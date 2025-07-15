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

// https://leetcode.com/problems/binary-search/

class Solution {
public:
    int bSearch(vi& a, int l, int r, int key) {
      if(l >= r) {
        if(l == r && key == a[l]) return l;
        else return -1;
      }
      int m = (l+r)/2;
      if(key < a[m]) return bSearch(a, l, m-1, key);
      else if(key > a[m]) return bSearch(a, m+1, r, key);
      else return m;
    }

    int search(vector<int>& nums, int target) {     // O(log n)
      return bSearch(nums, 0, nums.size()-1, target);
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
    int target;
    cin >> target;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int res = sol.search(nums, target);
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
