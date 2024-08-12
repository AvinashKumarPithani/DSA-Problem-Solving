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

// https://www.spoj.com/problems/NAJPWG/
// Given an integer n. find out how many pair (x, y) can be possible in range n, which gcd is greater than 1
// Phi(n) = count of number of integers b/w [1,n] which are relatively prime to n.
// O(N*loglogN)

const int N = 100000;
int ph[N+1];
ll pre[N+1];

void phi(){     
    FOR(i, 1, N+1) ph[i] = i;
    FOR(i, 2, N+1){
        if(ph[i] == i){
            FORk(j, i, N+1, i){
                ph[j] = ph[j] - ph[j]/i;
            }
        }
    }
    // Precomputing cumulative sum of phi values
    FOR(i, 1, N+1){       
        pre[i] = pre[i-1] + ph[i];  // pre[i] = no. of pairs in range [1, i] whose (GCD=1)
    }
}

void solve() {
    int n;
    cin >> n;
    ll tp = (ll)n * (n+1) / 2;  // total_pairs
    cout << tp - pre[n];    //  total_pairs - (no. of pairs in range [1, n] whose GCD = 1)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    phi();
    int x = t;
    while(t--) {
        cout << "Case " << x-t << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}