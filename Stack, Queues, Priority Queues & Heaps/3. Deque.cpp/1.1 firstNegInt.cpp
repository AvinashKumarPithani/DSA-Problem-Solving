#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<b; i+=k)
#define rFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define rFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
#define pf push_front
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
const int MOD = 1e9+7;

// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {    // O(n)
      int n = arr.size();
      vi ans;
      deque<int> d;   // using deque
      FOR(i, 0, k) {
        if(arr[i] < 0) d.pb(i);
      }
      FOR(i, 0, n-k+1) {
        if(!d.empty() && d.front() < i) d.pop_front();

        if(!d.empty()) ans.pb(arr[d.front()]);
        else ans.pb(0);
        
        if(i < n-k && arr[i+k] < 0) d.pb(i+k);  
      }
      return ans;
    }
};

void solve(Solution sol) { 
    string line;
    getline(cin, line); // Read the whole line
    istringstream iss1(line); // Create stream from line
    vi nums;
    int x;
    while (iss1 >> x) {     
      nums.pb(x); // Extract numbers one by one 
    }
    int k;
    cin >> k;
    vi res = sol.firstNegInt(nums, k);
    for(auto i: res) cout << i << " ";
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
