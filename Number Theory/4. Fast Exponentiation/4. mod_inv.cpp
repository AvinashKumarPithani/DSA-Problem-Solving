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

// Modulo inverse of x mod MOD, where MOD is prime, can be calculated using Fermat's Little Theorem as x^(MOD-2) mod MOD

const int MOD = 7; // Prime
ll pow(int a, int b){   // TC: O(log b)  SC: O(log b)
    if(b == 0) return 1;
    ll ans = pow(a, b/2);
    ans = (ans*ans) % MOD;
    if(b % 2 == 1) ans = (ans*a) % MOD;
    return ans;
}

ll mod_inv(int x){  // TC: O(log MOD)  SC: O(log MOD)
    return pow(x, MOD-2);
}
void solve() {  // TC: O(log MOD)
    int x;
    cin >> x;
    cout << mod_inv(x);
}

int main() {    // O(t*log MOD)
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