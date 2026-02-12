#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b) for(int i=(a); i<b; i+=k)
#define rFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define rFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vll;
typedef vector<ull> vull;

// https://codeforces.com/problemset/problem/17/A
// Noldbach problem states that at least k prime numbers from 2 to n inclusively can be expressed as the sum of three integer numbers: two neighboring prime numbers and 1. For example, 19 = 7 + 11 + 1, or 13 = 5 + 7 + 1.
const int N = 1000;
bool pr[N+1];
vi prs;
bool nold[N+1];
void sieve() {      // O(N*loglogN)
    FOR(i, 2, N+1) pr[i] = true;
    for(int i=2; i*i<=N; i++){
        if(pr[i]){
            for(int j=i*i; j<=N; j+=i){
                pr[j] = false;
            }
        }
    }
    FOR(i, 2, N+1){
        if(pr[i]){
            prs.pb(i);
        }
    }
    int x = prs.size();
    FOR(i, 1, x){
        int r = prs[i]+prs[i-1]+1;
        if(r>N) break;
        if(pr[r]){
            nold[r] = true;
        }
    }
}
// O(N*loglogN) solution
void solve() {
    int n,k;
    cin >> n >> k;
    int c = 0;
    
    FOR(i, 2, n+1){
        if(nold[i]){
            c++;
            // cout << i << " ";
        }
    }
    // cout << '\n';
    if(c>=k){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}
// Codeforces 17A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    sieve();
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}