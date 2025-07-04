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
    int partition(vll& a, int l, int h) {
      ll pivot = a[h];
      int i = l-1;
      FOR(j, l, h) {
        if(a[j] <= pivot) {
          i++;
          swap(a[i], a[j]);
        }
      }
      i++;
      swap(a[i], a[h]);
      return i;
    }
    void quickSort(vll& a, int l, int h) {
      if(l>=h) return;
      int pidx = partition(a, l, h);
      quickSort(a, l, pidx-1);
      quickSort(a, pidx+1, h);      
    }
    void sortIt(vector<long long>& arr) {     // TC: O(n*log n), SC: O(1)
      int n = arr.size();
      quickSort(arr, 0, n-1);
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