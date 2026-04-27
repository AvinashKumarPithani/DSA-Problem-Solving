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
// const int MOD = 1e9+7;  // Standard prime modulo
// const int MOD = 2147483647; // Max int value; use when 1e9+7 is too small

// https://leetcode.com/problems/student-attendance-record-i/
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) and doesn't contain more than two continuous 'L' (late).

class Solution {
public:
    bool checkRecord(string& s) {   // O(n)  SC: O(1)
        int n = s.length();
        int a = 0;
        // vector<int> l(n,0);
        int l = 0;
        if(s[0]=='A') a++;
        // else if(s[0]=='L') l[0]++;
        else if(s[0]=='L') l++;
        for(int i=1; i<n; i++) {
            if(s[i]=='A') a++;
            if(a>1) return false;
            // if(s[i]=='L') l[i] = l[i-1]+1;
            // if(l[i]>2) return false;
            if(s[i]=='L') l = l+1;
            else l = 0;
            if(l>2) return false; 
        }
        return true;
    }
};

void solve(Solution& sol) {   // O(n)
    // int n;
    // cin >> n;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    // getline(cin, line); // Read the whole line

    // istringstream iss(line); // Create stream from line
    // vi nums;
    // int x;
    // while (iss >> x) {
    //   nums.pb(x); // Extract numbers one by one
    // }
    cin >> line;
    bool res = sol.checkRecord(line);
    (res==true) ? cout << "true" : cout << "false";
}

int main() {    // O(n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}