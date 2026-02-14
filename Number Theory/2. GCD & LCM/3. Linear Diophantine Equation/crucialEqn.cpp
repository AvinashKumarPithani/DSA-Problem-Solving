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

// https://www.spoj.com/problems/CEQU/
// given three integers a, b and c. Find if there exist two integers x and y such that ax + by = c. i.e. linear diophantine equation or not.

int gcd(int a, int b){      // O(log(min(a, b)))
    if(b == 0) return a;
    return gcd(b, a%b);
}
void solve() {      // O(log(min(a, b)))
    int a, b, c;
    cin >> a >> b >> c;
    if(c % gcd(a, b) == 0) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    int x = t;
    while(t--) {
        cout << "Case " << x-t << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}