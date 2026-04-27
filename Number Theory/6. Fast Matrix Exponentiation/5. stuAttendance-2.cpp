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

// Recursive approach with pruning - TLE for larger n > 27

class Solution {
public:
    int numberOfValidRecords(int n, int a, int l) {  // TC: O(3^n)  SC: O(n)
        if(a>1 || l>2)  // pruning condition
            return 0;
        if(n==0)
            return 1;
        int L = numberOfValidRecords(n-1, a, l+1);
        int A = numberOfValidRecords(n-1, a+1, 0);
        int P = numberOfValidRecords(n-1, a, 0);
        return ((L + A) % MOD + P) % MOD;
    }
    int checkRecord(int n) {   // TC: O(3^n)  SC: O(n)
        return numberOfValidRecords(n, 0, 0);
    }
};

void solve(Solution& sol) {   // O(3^n)
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

int main() {    // O(t*3^n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}