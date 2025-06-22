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
const int N = 1e5;
ll f[N];

void pre_fact() {
  f[0] = 1;
  FOR(i, 1, N+1) {
    f[i] = (i*f[i-1]) % MOD;
  }
}

ll fact(int n) {
  ll res = 1;
  FOR(i, 1, n+1) {
    res = (res*i) % MOD;
  }
  return res;
}

ll pow(int a, int b){
  if(b == 0) return 1;
  ll ans = pow(a, b/2);
  ans = (ans*ans) % MOD;
  if(b % 2 == 1) ans = (ans*a) % MOD;
  // cout << endl <<ans;
  return ans;
}


ll mod_inv(int x) {
  return pow(x, MOD-2);
}

int ncr(int n, int r) {   // O(log MOD)
  ll nf = f[n];
  ll nrfi = mod_inv(f[n-r]);
  ll rfi = mod_inv(f[r]);
  // cout << endl << nf << " " << nrfi << " " << rfi;
  return (((nf*nrfi)%MOD)*rfi)%MOD;
}

void solve() {
  int n, r;
  cin >> n >> r;
  cout << ncr(n, r);
}

int main() {    // O(n + t*log MOD)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  pre_fact();
  while(t--) {
      solve();
      cout << '\n';
  }
  return 0;
}