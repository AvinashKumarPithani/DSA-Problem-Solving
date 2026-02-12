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

// https://codeforces.com/problemset/problem/26/A
// A number is called almost prime if it has exactly two distinct prime divisors. For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not. Find the amount of almost prime numbers which are between 1 and n, inclusive.+ 7 + 1.
const int N = 3000;
bool pr[N+1];
vi prs;
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
}

void solve() {      // O(n*P) where P is the number of primes less than N
    int n;
    cin >> n;
    int almostPrimes = 0;
    int x = prs.size();
    FOR(i, 2, n+1){
        int c = 0;
        FOR(j, 0, x){
            int d = prs[j];
            if(i < d) break;
            if(i%d==0) {
              c++;
            }
            if(c>2) break;
        }
        if(c==2){
            almostPrimes++;
        }
    }
    cout << almostPrimes;
}
// Codeforces 26A
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