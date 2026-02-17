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

// Given an integer n. Find Phi(n) // Optimized approach
// Phi(n) = count of number of integers b/w [1,n] which are relatively prime to n.

int phi(int n){     //O(n^0.5)
    int res = n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n = n/i;
            }
            res = res - res/i;
        }
    }
    if(n > 1) res = res - res/n;
    return res;
}

void solve() {      // O(sqrt(n))
    int n;
    cin >> n;
    cout << phi(n);
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