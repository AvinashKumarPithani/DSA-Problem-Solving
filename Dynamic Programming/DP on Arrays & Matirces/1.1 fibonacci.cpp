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

// const int N = 30;
// vi memo(N+1, -1);


class Solution {
public:
    // Tabulation
    int fib(int n) { // TC: O(n), SC: O(1)
        if(n == 0) return 0;
        if(n == 1) return 1;
        int last = 1, secondLast = 0, temp;
        FOR(i, 2, n+1) {
            temp = last;;
            last = last + secondLast;
            secondLast = temp;
        }
        return last;
    }
};

void solve() { // TC: O(n), SC: O(1)
    int n;
    cin >> n;
    Solution sol;
    cout << sol.fib(n);
}

int main() {  // TC: O(t*n), SC: O(1) 
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