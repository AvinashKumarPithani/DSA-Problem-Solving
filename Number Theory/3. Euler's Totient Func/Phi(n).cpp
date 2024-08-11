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

// Given an integer n. Find Phi(n) // brute force
// Phi(n) = count of number of integers b/w [1,n] which are relatively prime to n.

int gcd(int a, int b){      //O(logn)
    if(b == 0) return a;
    return gcd(b, a%b); 
}

int phi(int n){     //O(nlogn)
    int c = 1;
    FOR(i, 2, n+1){
        if(gcd(i, n) == 1){
            c++;
        }
    }
    return c;
}

void solve() {
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