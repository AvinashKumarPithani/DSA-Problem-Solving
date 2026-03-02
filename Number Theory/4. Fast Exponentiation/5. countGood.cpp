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

// https://leetcode.com/problems/count-good-numbers/

const int MOD = 1e9+7;
ll pow(int a, ll b){    // TC: O(log b)  SC: O(log b)
    if(b == 0) return 1;
    ll ans = pow(a, b/2);
    ans = (ans*ans) % MOD;
    if(b % 2 == 1) ans = (ans*a) % MOD;
    return ans;
}

int countGoodNumbers(long long n) {  // TC: O(log n)  SC: O(log n)
    ll res = 1;
    res = (res*pow(5, n/2)) % MOD;  // for odd places (1, 3, 5, 7, 9) --> 5 options
    res = (res*pow(4, n/2)) % MOD;  // for even places (0, 2, 4, 6, 8) --> 4 options
    if(n&1) res = (res*5) % MOD;     // if n is odd, then we have one extra odd place with 5 options

    return res; 
}

void solve() {  // TC: O(log n)
    ll n;
    cin >> n;
    cout << countGoodNumbers(n);
}

int main() {    // O(t*log n)
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