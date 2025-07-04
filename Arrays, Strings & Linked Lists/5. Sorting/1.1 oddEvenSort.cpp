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

// https://www.geeksforgeeks.org/problems/sort-in-specific-order2422/1

class Solution {
  public:
    void moe(vll& a, int l, int m, int h) {
      vll merged;
      int idx1 = l;
      int idx2 = m+1;
      while(idx1 <= m && idx2 <= h) {
        if((a[idx1]&1) && (a[idx2]&1)){
          if(a[idx1] > a[idx2]) merged.pb(a[idx1++]);
          else merged.pb(a[idx2++]);
        }
        else if((a[idx1]&1) && !(a[idx2]&1)) {
          merged.pb(a[idx1++]);
        }
        else if(!(a[idx1]&1) && (a[idx2]&1)) {
          merged.pb(a[idx2++]);
        }
        else {
          if(a[idx1] < a[idx2]) merged.pb(a[idx1++]);
          else merged.pb(a[idx2++]);
        }
      }
      while(idx1 <= m) {
        merged.pb(a[idx1++]);
      }
      while(idx2 <= h) {
        merged.pb(a[idx2++]);
      }
      int j = 0;
      FOR(i, l, h+1) {
        a[i] = merged[j++];
      }
    }
    void msoe(vll& a, int l, int h) {
      if(l>=h) return;
      int m = (l+h)/2;
      msoe(a, l, m);
      msoe(a, m+1, h);
      moe(a, l, m, h);
    }
    void sortIt(vector<long long>& arr) {     // TC: O(n*log n), SC: O(n)
      int n = arr.size();
      msoe(arr, 0, n-1);
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vll nums;
    int x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    sol.sortIt(nums);
    for(auto i: nums) {
      cout << i << " ";
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