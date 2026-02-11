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

// SPOJ: PFACT - Prime Factors
const int N = 100000;
bool pr[N+1];
void sieve(){       // O(N*loglogN)
    FOR(i,2,N+1) pr[i] = true;
    for(int i=2; i*i<=N; i++){
        if(pr[i]){
            FORk(j, i*i, N+1, i){
                pr[j] = false;
            }
        }
    }
}
void solve() {     // O(N^2)
    FOR(i, 2, N+1){
        cout << i << ": ";
        if(pr[i]) cout << i;
        else{
            FOR(j, 2, i+1){
            	// if(j>i) break;
                if(pr[j] && i%j==0){
                    cout << j << " ";
                }
            }
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