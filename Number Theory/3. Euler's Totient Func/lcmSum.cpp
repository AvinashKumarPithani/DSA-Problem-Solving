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

// https://www.spoj.com/problems/LCMSUM/
// Given a number n, find the sum of lcm(i, n) for i = 1 to n.

// Brute force 

void solve() {      // O(n^2)
    int n;
    cin >> n;
    ll s = 0;
    FOR(i, 1, n+1){
        int k = 1;
        while(k){
            if((n*k)%i == 0){
                s += n*k;
                break;
            }
            k++;
        }
    }
    cout << s;
}

int main() {
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