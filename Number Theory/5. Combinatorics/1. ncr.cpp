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

const int MOD = 1e9+7;
ll fact(int n) {
  ll res = 1;
  FOR(i, 1, n+1) {
    res = (res*i)%MOD;
  }
  // cout << endl << res;
  return res;
}

// ll pow(ll a, ll b) {
//   ll ans = 1;
//   while(b){
//     if(b&1) ans = (ans*a) % MOD;
//     a = (a*a) % MOD;
//     b = b>>1;
//   }
//   cout << endl <<ans;
//   return ans;
// }

// ll pow(int a, int b){
//     if(b == 0) return 1;
//     ll ans = pow(a, b/2);
//     ans = (ans*ans) % MOD;
//     if(b % 2 == 1) ans = (ans*a) % MOD;
//     cout << endl <<ans;
//     return ans;
// }


// ll mod_inv(ll x) {
//   return pow(x, MOD-2);
// }

ll mod_inv(int x){
  ll a = x;
  int b = MOD-2;
  ll ans = 1;
  while(b){
    if(b&1) ans = (ans*a) % MOD;
    a = (a*a) % MOD;
    b = b>>1;
  }
  // cout << endl <<ans;
  return ans;
  // return pow(x, MOD-2);
}

int ncr(int n, int r) {
  ll nf = fact(n);
  ll nrfi = mod_inv(fact(n-r));
  ll rfi = mod_inv(fact(r));
  // cout << endl << nf << " " << nrfi << " " << rfi;
  return (((nf*nrfi)%MOD)*rfi)%MOD;
}

void solve() {
  int n, r;
  cin >> n >> r;
  cout << ncr(n, r);
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