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

// https://leetcode.com/problems/student-attendance-record-ii/
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) and doesn't contain more than two continuous 'L' (late). Find the total number of possible attendance records of length n that would make a student eligible for an attendance award. The answer may be very large, so return it modulo 10^9 + 7.

// Fast matrix exponentiation approach

/*
State Representation:

0 -> (1A, 0 trailing L)
1 -> (1A, 1 trailing L)
2 -> (1A, 2 trailing L)
3 -> (0A, 0 trailing L)
4 -> (0A, 1 trailing L)
5 -> (0A, 2 trailing L)

Let vi denote the state vector for valid strings of length i.

The transition matrix M is constructed such that:

    v(i+1) = M * vi

A key observation is that:

    v(i+1)[0] = sum of all states in vi

Therefore, state 0 of the next vector stores the total number
of valid strings of the current length.

For example:

    v2 = {3,1,0,2,1,1}
    v3 = {8,3,1,4,2,1}
    v4 = {19,8,3,4,4,2}

and:

    v2[0] = 3  = answer(1)
    v3[0] = 8  = answer(2)
    v4[0] = 19 = answer(3)

Hence:

    answer(n) = v(n+1)[0]

Using

    v2 = {3,1,0,2,1,1}

as the base vector:

    v(n+1) = M^(n-1) * v2

Therefore, after computing M^(n-1), the required answer is:

    row0(M^(n-1)) · v2

which is exactly what the final expression computes.
*/

typedef struct {
    ll m[6][6];
} matrix;

matrix mul(matrix a, matrix b) {    // O(1)
    matrix c;
    FOR(i, 0, 6) {
        FOR(j, 0, 6) {
            c.m[i][j] = 0;
            FOR(k, 0, 6) {
                c.m[i][j] = ( c.m[i][j] + a.m[i][k] * b.m[k][j] ) % MOD;
            }
        }
    }
    return c;
}

matrix pow(matrix a, int b) {   // O(log b)
    if(b==1) return a;
    matrix ans = pow(a, b/2);
    ans = mul(ans, ans);
    if(b%2!=0) ans = mul(ans, a);
    return ans;
}

class Solution {
public:
    int checkRecord(int n) {    // TC: O(log n)  SC: O(1)
        if(n==0) return 1;
        if(n==1) return 3;
        matrix m {{
            {1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {0, 0, 0, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
        }};
        m = pow(m, n-1);    // O(log n)
        return (3*m.m[0][0] + 1*m.m[0][1] + 0*m.m[0][2] +
                2*m.m[0][3] + 1*m.m[0][4] + 1*m.m[0][5])%MOD;
    }
};

void solve(Solution& sol) {   // O(log n)
    int n;
    cin >> n;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    // getline(cin, line); // Read the whole line

    // istringstream iss(line); // Create stream from line
    // vi nums;
    // int x;
    // while (iss >> x) {
    //   nums.pb(x); // Extract numbers one by one
    // }
    // cin >> line;
    int res = sol.checkRecord(n);
    cout << res;
}

int main() {    // O(t*log n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Solution obj = Solution();
    // memset(dp, 0, sizeof(dp));
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}