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

// https://www.spoj.com/problems/TDKPRIME/

const int N = 86028121; //50,00,000 th prime i.e. (10^6)th prime found in (10^8)s
bool pr[N+1];
vi prs;
void sieve(){
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
}
// Kth prime in O(NloglogN)
void solve() {
    int k;
    cin >> k;
    // cout << prs.size()<<endl;
    // cout << prs[5000000-1];
    cout << prs[k-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    sieve();
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}