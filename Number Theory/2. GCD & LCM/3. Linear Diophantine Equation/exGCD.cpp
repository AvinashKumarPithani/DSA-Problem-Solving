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

// Finding one of the integral solutions of the given equation

int ex_gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0; // it can be any value i.e. y = 0,1,2,3,..
        return a;
    }
    int x0, y0;
    int g = ex_gcd(b, a%b, x0, y0);
    x = y0;
    y = x0 - (a/b)*y0;
    return g;
}
void solve() {
    int a, b, c, x, y, g;
    cin >> a >> b >> c;
    if(a > b) g = ex_gcd(a, b, x, y);
    else g = ex_gcd(b, a, y, x);
    if(c % g == 0){
        cout << "One of the Integral Solutions = ";
        cout << "x: " << (c/g)*x << ", y: " << (c/g)*y;
    }
    else cout << "No Integral Solution";
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