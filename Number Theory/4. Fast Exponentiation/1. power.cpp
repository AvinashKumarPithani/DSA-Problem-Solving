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

int pow(int a, int b){      // TC: O(log b)  SC: O(log b)
    if(b == 0) return 1;
    int ans = pow(a, b/2);
    ans *= ans;
    if(b % 2 == 1) ans *= a;
    return ans;
}

void solve() {      // TC: O(log b)
    int a, b;
    cin >> a >> b;
    cout << pow(a, b);
}

int main() {        // O(t*log b)
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