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
const int MOD = 1e9+7;

// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    int k;
    KthLargest(int k, vector<int>& nums) {
      this->k = k;
      FOR(i, 0, nums.size()) {
        pq.push(nums[i]);
        if(pq.size() > k) {
            pq.pop();
        }
      }
    }
    int add(int val) {
      pq.push(val);
      if(pq.size() > k) {
          pq.pop();
      }
      return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Example Input:
// 2
// KthLargest add add add add add
// 3
// 4 5 8 2
// 3 5 10 9 4
// KthLargest add add add add add
// 1
// []
// -3 -2 -4 0 4

void solve() {      // O(n*log k)
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vs inp;
    string s;
    while (iss >> s) {
        inp.pb(s); // Extract numbers one by one
    }
    
    if(inp[0] != "KthLargest") {
      cout << "The first input method name should be the Constructor name.";
    }
    else {
      int k;
      cin >> k;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      string line;
      getline(cin, line); // Read the whole line

      istringstream iss(line); // Create stream from line
      vi nums;
      int x;
      while (iss >> x) {
        nums.pb(x); // Extract numbers one by one
      }
      KthLargest* obj = new KthLargest(k, nums);
      cout << "null ";
      FOR(i, 1, inp.size()) {
        cin >> x;
        if(inp[i] == "add") {
          cout << obj->add(x) << " ";
        } else {
          cout << '\n' << "Invalid method name: " << inp[i] << '\n';
        }
      }
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}