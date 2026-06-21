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

// approach using Fast matrix exponentiation

/*
State Representation:

0 -> (0A, 0 trailing L)
1 -> (0A, 1 trailing L)
2 -> (0A, 2 trailing L)
3 -> (1A, 0 trailing L)
4 -> (1A, 1 trailing L)
5 -> (1A, 2 trailing L)

Only two pieces of information matter while building the string:

    1. Number of A's used so far (0 or 1)
    2. Number of consecutive trailing L's (0, 1 or 2)

Let vi denote the state vector for valid strings of length i.

Initial state:

    v0 = {1,0,0,0,0,0}

representing the empty string.

The transition matrix M is built from all valid moves:

    Add 'P' -> trailing L count becomes 0
    Add 'L' -> trailing L count increases by 1 (max 2)
    Add 'A' -> allowed only if no A has been used yet

Thus:

    v(i+1) = M * vi

and after n transitions:

    vn = M^n * v0

The answer is the sum of all states in vn since each state
represents a distinct class of valid strings of length n.

Since v0 = {1,0,0,0,0,0}ᵀ,

    vn = M^n * v0

is simply the first column of M^n.

Therefore:

    answer(n) = Σ M^n[i][0]

Matrix exponentiation computes M^n in O(log n) time.
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
    int numberOfValidRecords(int n) {  // TC: O(log n)  SC: O(1)
        if(n==0) return 1;
        matrix m {{
            {1, 1, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1},
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0},
        }};
        m = pow(m, n);  // O(log n)
        int res = 0;
        FOR(i, 0, 6) {
            res = (res + m.m[i][0]) % MOD;
        }
        return res;
    }
    int checkRecord(int n) {   // TC: O(log n)  SC: O(1)
        return numberOfValidRecords(n);
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