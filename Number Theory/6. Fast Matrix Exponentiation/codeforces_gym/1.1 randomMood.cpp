#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<b; i+=k)
#define rFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define rFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
#define pf push_front
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<bool> vb;
const int MOD = 1e9+7;  // Standard prime modulo
// const int MOD = 2147483647; // Max int value; use when 1e9+7 is too small

// https://codeforces.com/gym/102644/problem/A
/* 
This is a training contest on matrix exponentiation. See the tutorial along with hints and video solutions here.

Limak is always either happy or sad. His mood switches with probability p
 every second. If Limak is happy right now, what is the probability that he's happy after n
 seconds?

Input
An integer n (1≤n≤109) and a real value p(0<p<1) with at most 9 digits after floating point.

Output
Print one line with the answer. The absolute error allowed is 10^(−6).

*/

// Matrix Exponentiation approach

typedef struct {
    double m[6][6];
} matrix;

matrix mul(matrix a, matrix b) {    // O(1)
    matrix c;
    FOR(i, 0, 2) {
        FOR(j, 0, 2) {
            c.m[i][j] = 0;
            FOR(k, 0, 2) {
                c.m[i][j] = ( c.m[i][j] + a.m[i][k] * b.m[k][j] );
            }
        }
    }
    return c;
}

matrix pow(matrix a, ll b) {   // O(log b)
    if(b==1) return a;
    matrix ans = pow(a, b/2);
    ans = mul(ans, ans);
    if(b%2!=0) ans = mul(ans, a);
    return ans;
}

class Solution {
public:
    double randomMood(ll n, double p) {    // TC: O(log n)  SC: O(1)
        if(n==0) {
            return 1.0;
        }
        matrix T = {{
            {1-p, p},
            {p, 1-p}
        }};
        matrix T_n = pow(T, n);
        double ans = T_n.m[0][0]; // Probability of being happy after n seconds
        return ans;
    }
};

void solve(Solution& sol) {   // O(log n)
    ll n;
    double p;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // string line;
    // getline(cin, line); // Read the whole line

    // istringstream iss(line); // Create stream from line
    // vi nums;
    // int x;
    // while (iss >> x) {
    //   nums.pb(x); // Extract numbers one by one
    // }
    // cin >> line;
    while(cin >> n >> p) {
        double res = sol.randomMood(n, p);
        cout << fixed << setprecision(10); // Set precision to 10 decimal places
        cout << res << '\n';
    }
}

int main() {    // O(t*log n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Solution obj = Solution();
    // memset(dp, 0, sizeof(dp));
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}