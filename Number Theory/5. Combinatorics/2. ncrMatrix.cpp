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
const int N = 10;

ll ncrMat[N+1][N+1];

void pre_compute() {
  ncrMat[0][0] = 1;
  FOR(i, 1, N+1) {
    ncrMat[i][0] = 1;
    ncrMat[i][i] = 1;
    FOR(j, 1, N) {
      ncrMat[i][j] = ncrMat[i-1][j] + ncrMat[i-1][j-1];
    }
  }
}

void printMat(){
  FOR(i, 0, N+1) {
    FOR(j, 0, N+1) {
      cout << ncrMat[i][j] << " ";
    }
    cout << '\n';
  }
}

void solve() {
  int n, r;
  cin >> n >> r;
  cout << ncrMat[n][r]; // O(1)
}

int main() {    // O(N + T)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    pre_compute(); // O(N)
    // printMat();
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}