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

// https://www.geeksforgeeks.org/problems/koko-eating-bananas/1

class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {      // iterative binarySearch -- O(n*log m) 
      int n = arr.size();
      int m = *max_element(arr.begin(), arr.end());
      // int s = m;
      int l = 1, r = m;
      while(l < r) {  
        int mid = (l+r)/2;
        int h = 0;
        for(auto j : arr) {
          h += ceil(j*1.0/mid);
        }
        if(h <= k) r = mid;
        else l = mid + 1;
      }
      return l;
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
    int res = sol.kokoEat(nums, k);
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
