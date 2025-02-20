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
const int N = 1000;
bool pr[N+1];
vi prs;
void sieve() {
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
// O(N^2) solution
void solve() {
    int n,k;
    cin >> n >> k;
    int c = 0;
    int x = prs.size();
    FOR(i, 5, n){
        if(pr[i]){
            FOR(j, 1, x){
                int r = prs[j-1] + prs[j] + 1;
                if(r > i) break;
                if( r == i){
                    cout << i << " ";
                    c++;
                    break;
                }
            }
        }
    }
    cout<< endl;
    if(c==k){
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
    cin >> t;
    sieve();
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}