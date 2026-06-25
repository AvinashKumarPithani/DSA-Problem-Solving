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

// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1
// Given an array of 0s and 1s, segregate the 0s and 1s in the array such that all 0s are on the left side and all 1s are on the right side of the array.

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {  // O(n)
        // code here
        int l, h;
        l = 0;
        h = arr.size()-1;
        while(l < h) {
          if(arr[l] == 0) {
            l++;
          }
          else{
            swap(arr[l], arr[h]);
            h--;
          }
        }
    }
};

void solve(Solution sol) {  // O(n)
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vi nums;
    int x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    sol.segregate0and1(nums);
    for(auto i: nums) {
      cout << i << " ";
    }    
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