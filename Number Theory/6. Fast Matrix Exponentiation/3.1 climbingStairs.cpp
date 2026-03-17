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
const int MOD = 2147483647; // 2^31 > 1e9+7

// https://leetcode.com/problems/climbing-stairs/

// The number of ways to climb n stairs is the sum of the ways to climb n-1 stairs and n-2 stairs, which is the Fibonacci sequence. We can use dynamic programming to solve this problem in O(n) time and O(1) space by keeping track of the last two values.

typedef struct {
  ll m[2][2];
} matrix;

matrix identity_matrix() {
  return matrix {{
    {1, 0},
    {0, 1}
  }};
}

matrix mul(matrix &a, matrix &b) {  // TC: O(1)  SC: O(1)
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

matrix pow(matrix &a, int b) {  // TC: O(log b)  SC: O(1)
  if(b==0) return identity_matrix();
  matrix ans = pow(a, b/2);
  ans = mul(ans, ans);
  if(b&1) ans = mul(ans, a);
  return ans;
}

int climbStairs(int n) {    // TC: O(log n)  SC: O(1)
    matrix x = {{
        {1, 1},
        {1, 0}
    }};
    matrix res = pow(x, n-1);
    return res.m[0][0] + res.m[0][1];
    // OR
    // matrix res = pow(x, n-2);
    // return 2*res.m[0][0] - res.m[1][0];  
}

void solve() {      // TC: O(log n)
    int n;
    cin >> n;
    cout << climbStairs(n);
}

int main() {        // O(t * log n)
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