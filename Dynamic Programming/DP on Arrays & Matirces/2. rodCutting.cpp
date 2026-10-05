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

// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution {
  public:
    //Memoization
    int maxProfit(int n, vi& p, vi& memo) {

        if(memo[n] == -1) {
            FOR(i, 1, n+1) {
                memo[n] = max( memo[n], p[i-1] + maxProfit(n-i, p, memo) );
            }
        }
        return memo[n];
    }
    
    int cutRod(vector<int> &price) {    // TC: O(n^2), SC: O(n)
        // code here
        int n = price.size();
        vi memo(n+1, -1);
        memo[0] = 0;
        return maxProfit(n, price, memo);
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    // Replace '[', ']', and ',' with spaces
    for (char &ch : line) {
        if (ch == '[' || ch == ']' || ch == ',') {
            ch = ' '; // saves time rather than erasing them
        }
    }

    istringstream iss(line); // Create stream from line
    vi nums;
    ll x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    cout << sol.cutRod(nums);
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