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

// https://codeforces.com/problemset/problem/1978/B

ll pr(int n, int a, int b, int k) {
    return (ll)k*b - (ll)k*(k-1)/2 + (ll)(n-k)*a;
} 

void solve() {    // O(1) -- runs in 46 ms, which is better than solution with class/obj whose run time is 62 ms.
    int n, a, b;
    cin >> n >> a >> b;   
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ll res;
    if(b <= a) res = pr(n, a, b, 0);
    else res = pr(n, a, b, min(n, b-a));
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}
