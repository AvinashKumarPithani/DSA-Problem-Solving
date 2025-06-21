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

// https://leetcode.com/problems/powx-n/

double power(double a, long long b) { // O(log b)
    // if(b == 1) return a; 
    // If b == 0, the recursion never ends (because there's no base case), leading to infinite recursion and a stack overflow.
    if(b == 0) return 1.0; 
    double ans = power(a, b/2);
    ans *= ans;
    if(b&1) ans *= a;
    return ans; 
}
double myPow(double x, int n) { 
    // int r = n;
    long long r = n; // use long long to handle INT_MIN safely
    if(n < 0) r = -r;
    double res = power(x, r);
    if(n < 0) return 1.0/res;
    return res;
}

void solve() {
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n);
}

int main() {
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