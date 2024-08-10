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

const int sqm = 31623;
int pr[sqm];
vi prs;

void sieve(){
    FOR(i, 2, sqm+1) pr[i] = true;
    for(int i=2; i*i<=sqm; i++){
        if(pr[i]){
            FORk(j, i*i, sqm+1, i){
                pr[j] = false;
            }
        }
    }
    FOR(i, 2, sqm+1){
        if(pr[i]){
            prs.pb(i);
        }
    }
}
void segSieve(int N, int M){
    bool p[M-N+1];
    FOR(i, 0, M-N+1) p[i] = true;
    if(N == 1) p[0] = false; // Border Case when N=1
    int sqM = sqrt(M);
    for(auto i: prs){
        if(i > sqM){ // if i > sqM then i*i > M i.e. not in [N,M]
            break;
        }           
        int x = (N/i)*i;
        if(x < N) x += i;
        if(x < i*i) x = i*i;
        FORk(j, x, M+1, i){
            p[j-N] = false;
        }
    }
    FOR(i, N, M+1){
        if(p[i-N]) cout << i << " ";
    }
}

//Prime numbers between N & M using Segmented Sieve O(sqm*loglog(sqm)))
void solve() {
    int N,M;
    cin >> N >> M;
    segSieve(N, M);
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