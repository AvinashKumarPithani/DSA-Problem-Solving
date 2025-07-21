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

// https://leetcode.com/problems/valid-parentheses/


class Solution {
public:
    char cob(char &c) {
      if(c == '}') return '{';
      if(c == ')') return '(';
      return '[';
    }
    bool isValid(string s) {    // O(n)
      stack<char> st;
      for(auto i: s) {
        if(i == '{' || i == '(' || i == '[') st.push(i);
        else if(!st.empty() && st.top() == cob(i)) st.pop();
        else return false;
      }
      if(st.empty()) return true;
      return false;
    }
};

void solve(Solution sol) {
    string line;
    // getline(cin, line); // Read the whole line

    // istringstream iss(line); // Create stream from line
    // vi nums;
    // int x;
    // while (iss >> x) {
    //   nums.pb(x); // Extract numbers one by one
    // }
    // int k;
    // cin >> k;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin >> line;
    bool res = sol.isValid(line);
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
