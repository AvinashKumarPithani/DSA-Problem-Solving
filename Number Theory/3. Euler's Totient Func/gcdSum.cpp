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

// Given n, find the sum of gcd(n, i) for i = 1 to n. 
// Brute force approach

int gcd(int a, int b){      // O(log(min(a,b)))
    if(b==0) return a;
    return gcd(b, a%b);
}

void solve() {      // O(n*log n)
    int n;
    cin >> n;
    ll gcdSum = 0;
    FOR(i, 1, n+1) {
        gcdSum += (ll)gcd(n, i);    // O(log n)
    }
    cout << gcdSum;
}

int main() {     // O(t*n*log n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}