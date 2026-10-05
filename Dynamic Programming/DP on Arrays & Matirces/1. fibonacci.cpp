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

// https://leetcode.com/problems/fibonacci-number/

const int N = 30;
vi memo(N+1, -1);


class Solution {
public:
    // Memoization
    int fib(int n) { // TC: O(n), SC: O(1) since N is declared as global variable
        memo[0] = 0;
        memo[1] = 1;
        return f(n);
    }
    int f(int n) {
        if(memo[n] == -1) {
            memo[n] = fib(n-1)+fib(n-2);
        }
        return memo[n];
    }
};

void solve() { // TC: O(n), SC: O(1) since N is declared as global variable
    int n;
    cin >> n;
    Solution sol;
    cout << sol.fib(n);
}

int main() {  // TC: O(t*n), SC: O(N) 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}