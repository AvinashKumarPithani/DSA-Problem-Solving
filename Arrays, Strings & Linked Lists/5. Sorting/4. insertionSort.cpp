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
    void insertionSort(vll& a) {
      int n = a.size();
      FOR(i, 1, n) {
        // int j = i;
        // while(j && a[j] < a[j-1]) {
        //   swap(a[j], a[j-1]);
        //   j--;      
        // } 
        // or
        ll key = a[i];
        int j = i-1;
        while(j>=0 && key < a[j]) {
          a[j+1] = a[j];
          j--;
        }
        a[j+1] = key; 
      }
    }
    void sortIt(vector<long long>& arr) {     // TC: O(n^2)
      insertionSort(arr);
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