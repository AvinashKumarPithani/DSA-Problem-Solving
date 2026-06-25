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
typedef vector<bool> vb;
const int MOD = 1e9+7;

// https://leetcode.com/problems/majority-element-ii/
// Given an integer array of size n, find all elements that appear more than ⌊n/3⌋ times.

// Here we used the fact that there can be at most 2 elements that appear more than n/3 times. So we can use the same approach as in majorityElement1.cpp but with 2 candidates and 2 counts.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {  // O(n)
        int n = nums.size();
        vector<int> res;

        int c1 = 0;
        int c2 = 0;
        int e1 = INT_MIN;
        int e2 = INT_MIN;

        for(int i=0; i<n; i++) {
            if(c1==0 && nums[i] != e2) {
                c1 = 1;
                e1 = nums[i];
            }
            else if(c2==0 && nums[i] != e1) {
                c2 = 1;
                e2 = nums[i];
            }
            else if(nums[i] == e1) {
                c1++;
            }
            else if(nums[i] == e2) {
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == e1) c1++;
            else if(nums[i] == e2) c2++;
        }
        if(c1 > n/3) res.push_back(e1);
        if(c2 > n/3) res.push_back(e2);
        return res;
    }
};

void solve(Solution sol) {  // O(n)
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vi nums;
    int x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    vector<int> res = sol.majorityElement(nums);
    for(int i : res) {
        cout << i << " ";
    }
}

int main() {  // O(t*n)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}