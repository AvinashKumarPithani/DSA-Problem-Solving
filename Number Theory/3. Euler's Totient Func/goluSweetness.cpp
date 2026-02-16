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

// https://www.codechef.com/problems/COZIE
// Find no. of prime phi(a[i])'s in [l, r] range of the given array

int phi(int n){       // O(n^0.5)
    int res = n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n = n/i;
            }
            res = res - res/i;
        }
    }
    if(n > 1) res = res - res/n;
    return res;
}

bool is_prime(int n){       // O(n^0.5)
    if(n == 1) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void solve() {      // O(N * A^0.5 + q) where A = max(a[i]), q = no. of queries
    int n, q;
    cin >> n >> q;
    int a[n+1], ph[n+1], preS[n+1];
    a[0]=0, ph[0]=0, preS[0]=0;
    FOR(i, 1, n+1){
        cin >> a[i];
        ph[i] = phi(a[i]);
        if( is_prime(ph[i]) ){
            preS[i] = preS[i-1] + 1;
        }
        else{
            preS[i] = preS[i-1];
        }
    }
    // FOR(i, 0, n+1) cout << ph[i] << " ";
    // cout << '\n';
    // FOR(i, 0, n+1) cout << preS[i] << " ";
    // cout << '\n';
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << preS[r] - preS[l-1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}