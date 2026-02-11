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

// https://leetcode.com/problems/count-primes/submissions/1646500154/

// Count of Prime numbers from 2 to n using Sieve of Erathostenes in O(N*loglogN)
int countPrimes(int N) {
    if(N<2) return 0;
    bool pr[N+1];
    pr[0] = pr[1] = false;
    for(int i=2; i<N; i++) pr[i] = true;
    for(int i=2; i*i<N; i++){
        if(pr[i]){
            for(int j=i*i; j<=N; j+=i){
                pr[j] = false;
            }
        }
    }
    int c=0;
    for(int i=2; i<N; i++){
        if(pr[i]) c++;
    }
    return c;   
}

void solve() {
    int n;
    cin >> n;
    cout << countPrimes(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}