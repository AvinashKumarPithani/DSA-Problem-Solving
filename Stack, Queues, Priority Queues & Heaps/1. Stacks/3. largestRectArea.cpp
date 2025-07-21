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

// https://leetcode.com/problems/largest-rectangle-in-histogram/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {    // O(n)
      int n = heights.size();
      stack<int> s;
      vi nsr(n, n);
      rFOR(i, n-1, 0) {
        while(!s.empty() && heights[s.top()] >= heights[i]){
          s.pop();
        }
        if(!s.empty()) {
          nsr[i] = s.top();
        }
        s.push(i);
      }
      stack<int> st;
      vi nsl;
      FOR(i, 0, n) {
        while(!st.empty() && heights[st.top()] >= heights[i]){
          st.pop();
        }
        if(!st.empty()) {
          nsl.pb(st.top());
        }
        else {
          nsl.pb(-1);
        }
        st.push(i);
      }
      int a = 0;
      FOR(i, 0, n) {
        int h = heights[i];
        int w = nsr[i] - nsl[i] - 1;
        a = max(a, h*w);
      }
      return a;
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
    cout << sol.largestRectangleArea(nums);
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
