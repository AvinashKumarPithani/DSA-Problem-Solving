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

typedef struct {
  ll m[2][2];
} matrix;

matrix identity() {
  return matrix {{
    {1, 0},
    {0, 1}
  }};
}

matrix mul(matrix &a, matrix &b) {
  matrix c = {{
    {0, 0},
    {0, 0}
  }};
  FOR(i, 0, 2) {
    FOR(j, 0, 2) {
      FOR(k, 0, 2){
        c.m[i][j] = (c.m[i][j] + (a.m[i][k]*b.m[k][j])% MOD)% MOD;
      }
    }
  }
  return c;
}

matrix pow(matrix &a, int b) {
  if(b==0) return identity();
  matrix ans = pow(a, b/2);
  ans = mul(ans, ans);
  if(b&1) ans = mul(ans, a);
  return ans;
}

void solve() {
  // matrix x = {{
  //   {2, 3},
  //   {1, 2}
  // }};
  ll a, b, c, d;
  // cout << "Enter 2 by 2 Matrix:" << '\n';
  cin >> a >> b >> c >> d;
  
  int n;
  // cout << "Enter the power: ";
  cin >> n;

  matrix x = {{
    {a, b},
    {c, d}
  }};
  matrix res = pow(x, n);
  FOR(i, 0, 2) {
    FOR(j, 0, 2) {
      cout << res.m[i][j] << " ";
    }
    cout << '\n';
  }
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