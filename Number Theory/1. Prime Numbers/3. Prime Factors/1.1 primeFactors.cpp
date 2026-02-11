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

// https://www.spoj.com/problems/PFACT/
// printing prime factors of n such that (2 ≤ n ≤ 10^5)

const int N = 100000;
bool pr[N+1];

vector<vi> primeFactors(N+1);
void sieve(){       // O(N*loglogN)
    primeFactors[0] = primeFactors[1] = {};
    FOR(i,2,N+1) pr[i] = true;
    for(int i=2; i<=N; i++){
        if(pr[i]){
            FORk(j, i, N+1, i){
                if(i*i<=N) pr[j] = false;
                primeFactors[j].pb(i);
            }
        }
    }
}
void solve() {     // O(N*loglogN)
    FOR(i, 2, N+1){
        cout << i << ": ";
        for(auto j: primeFactors[i]){
            cout << j << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
        // cout << '\n';
    }
    return 0;
}