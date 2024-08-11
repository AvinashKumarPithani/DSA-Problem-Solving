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
// There is only one prime phi(n) vlaue i.e. 2 {for n = 3, 4, 6 }

void solve() {          // O(n)
    int n, q;
    cin >> n >> q;
    int a[n+1], preS[n+1];
    a[0]=0, preS[0]=0;
    FOR(i, 1, n+1){
        cin >> a[i];
        if( a[i] == 3 || a[i] == 4 || a[i] == 6 ){
            preS[i] = preS[i-1] + 1;
        }
        else{
            preS[i] = preS[i-1];
        }
    }
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