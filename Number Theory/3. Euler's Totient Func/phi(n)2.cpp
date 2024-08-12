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

// https://www.spoj.com/problems/ETF/
// Given an integer n. Find Phi(n) // Most Optimized approach (Modified Sieve method)
// Phi(n) = count of number of integers b/w [1,n] which are relatively prime to n.
// O(N*loglogN)

const int N = 1000000;
int ph[N+1];

void phi(){     
    FOR(i, 1, N+1) ph[i] = i;
    FOR(i, 2, N+1){
        if(ph[i] == i){
            FORk(j, i, N+1, i){
                ph[j] = ph[j] - ph[j]/i;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << ph[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    phi();
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}