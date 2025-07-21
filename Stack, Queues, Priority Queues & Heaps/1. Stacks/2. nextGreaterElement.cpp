#include <bits/stdc++.h>
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

// https://leetcode.com/problems/next-greater-element-i/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {    // brute-force -- O(N^2)
      int n1 = nums1.size();  
      int n2 = nums2.size();
      vi m;
      FOR(i, 0, n2) {
        int x = -1;
        FOR(j, i+1, n2) {
          if(nums2[j] > nums2[i]){
            x = nums2[j];
            break;
          }
        }
        m.pb(x);
      }
      vi ans;
      for(auto i: nums1) {
        FOR(j, 0, n2) {
          if(nums2[j] == i) {
            ans.pb(m[j]);
            break;
          }
        }
      }
      return ans;
    }
};

void solve(Solution sol) { 
    string line;
    getline(cin, line); // Read the whole line
    istringstream iss1(line); // Create stream from line
    vi nums1;
    int x;
    while (iss1 >> x) {     
      nums1.pb(x); // Extract numbers one by one 
    }

    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, line); // Read the whole line
    istringstream iss2 (line); // Create stream from line
    vi nums2;
    while (iss2 >> x) {     
      nums2.pb(x); // Extract numbers one by one 
    }
    vi res = sol.nextGreaterElement(nums1, nums2);
    for(auto i: res) {
      cout << i << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    Solution obj = Solution();
    while(t--) {
        solve(obj);
        cout << '\n';
    }
    return 0;
}
