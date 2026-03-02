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

// if we use pow(ll a, ll b), then it is conflicting with the built-in pow function. Si changed the name to power(ll a, ll b) when compared with the previous version recursive code.
ll power(ll a, ll b){    // TC: O(log b)  SC: O(1)
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a) % MOD;
        a = (a*a) % MOD;
        b = b>>1;
    }
    return ans; 
}

// one line logic optimization reduces half of recursion time i.e. 2 times faster than the previous code. 2*O(log n) --> O(log n)
int countGoodNumbers(long long n) {  // TC: O(log n)  SC: O(1)
    ll res = 1;
    res = (res*power(20, n/2)) % MOD; // Since 5 options for odd places (1,3,5,7,9) and 4 options for even places (0,2,4,6,8) --> 5*4 = 20
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