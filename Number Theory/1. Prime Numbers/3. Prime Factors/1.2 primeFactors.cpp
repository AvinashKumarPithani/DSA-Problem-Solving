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
    for(int i=2; i*i<=N; i++){      // -- wrong approach: we can stop at sqrt(N) because if i > sqrt(N) then i*i > N and we won't be able to add i as the prime factor of multiples of i > sqrt(N) i.e. (2*i, 3*i, ... are not always greater than N).
        if(pr[i]){
            FORk(j, i, N+1, i){
                pr[j] = false;
                primeFactors[j].pb(i);
            }
        }
    }
}
void solve() {     // O(N*loglogN)
    FOR(i, 2, N+1){
        cout << i << ": ";
        if(pr[i]) cout << i << " ";
        else{
            for(auto j: primeFactors[i]){
                cout << j << " ";
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