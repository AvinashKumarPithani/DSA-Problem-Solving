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

// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class comp {
  public:
    bool operator()(vi &v1, vi &v2) {
        return v1[1] < v2[1];
    }
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {    // O(n)
      sort(points.begin(), points.end(), comp());
      int c = points[0][1], ans = 1;
      FOR(i, 0, points.size()) {
        if(points[i][0] > c) {
          c = points[i][1];
          ans++;
        }
      }
      return ans;
    }
};

void solve(Solution sol) { 
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vector<vi> nums;
    vi x(2);
    while (iss >> x[0] >> x[1]) {     
      nums.pb(x); // Extract numbers pair by pair 
    }
    
    int res = sol.findMinArrowShots(nums);
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
