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

// Given n, find the sum of gcd(n, i) for i = 1 to n. (Gauss Theorem) -- Optimized approach

int phi(int n){     //O(n^0.5)
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

void solve() {      // O(n^0.5 * 2*n*0.5) => O(n)
    int n;
    cin >> n;
    int gcdSum = 0;
    for(int i=1; i*i <= n; i++) { 
      if(n%i == 0){
        gcdSum += (ll)phi(n/i) * i;    // O(sqrt(n))
        if(i*i != n) {
          gcdSum += (ll)phi(i) * (n/i);  // O(sqrt(n))
        }
      }
    }
    cout << gcdSum;
}

int main() {     // O(t*n)
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