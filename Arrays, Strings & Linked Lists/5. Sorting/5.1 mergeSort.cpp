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
    void merge(vll& a, int l, int m, int h) {
      vll left, right;
      FOR(i, l, m+1) {
        left.pb(a[i]);
      }
      FOR(i, m+1, h+1) {
        right.pb(a[i]);
      }
      left.pb(LONG_LONG_MAX);
      right.pb(LONG_LONG_MAX);
      int i=0, j=0;
      FOR(k, l, h+1) {
        if(left[i] < right[j]) a[k] = left[i++];
        else a[k] = right[j++];
      }
    }
    void mergeSort(vll& a, int l, int h) {
      if(l==h) return;
      int m = (l+h)/2;
      mergeSort(a, l, m);
      mergeSort(a, m+1, h);
      merge(a, l, m, h);
    }
    void sortIt(vector<long long>& arr) {     // TC: O(n*log n), SC: O(n)
      int n = arr.size();
      mergeSort(arr, 0, n-1);
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vll nums;
    ll x;
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