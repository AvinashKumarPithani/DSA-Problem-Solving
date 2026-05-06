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

// DP with tabulation - Bottom-up approach

const int N = 1e5+5;
int dp[N][2][3];  // DP table for tabulation

class Solution {
public:
    int numberOfValidRecords(int n) {  // TC: O(n)  SC: O(n)
        
        // Base case initialization for no.of days, n=0
        FOR(a, 0, 2) {
            FOR(l, 0, 3) {
                dp[0][a][l] = 1;
            }
        }
        FOR(i, 1, n+1) {
            FOR(a, 0, 2) {
                FOR(l, 0, 3) {
                    int L = (l+1 < 3) ? dp[i-1][a][l+1] : 0;
                    int A = (a+1 < 2) ? dp[i-1][a+1][0] : 0;
                    int P = dp[i-1][a][0];
                    dp[i][a][l] = ((L + A) % MOD + P) % MOD;
                }
            }
        }
        return dp[n][0][0];
    }
    int checkRecord(int n) {   // TC: O(n)  SC: O(n)
        return numberOfValidRecords(n);
    }
};

void solve(Solution& sol) {   // O(n)
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

int main() {    // O(t*n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Solution obj = Solution();
    memset(dp, 0, sizeof(dp));
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}