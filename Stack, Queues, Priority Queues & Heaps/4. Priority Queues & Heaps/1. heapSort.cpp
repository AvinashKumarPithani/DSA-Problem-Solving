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

// https://leetcode.com/problems/sort-an-array/

class Solution {
  public:
    // int HEAP_SIZE;
    void maxHeapify(vi& a, int heap_size, int i) {   // O(log n)
      int l = 2*i + 1;
      int r = 2*i + 2;
      int largest = i;
      if(l < heap_size && a[l] > a[largest]) {
        largest = l;
      }
      if(r < heap_size && a[r] > a[largest]) {
        largest = r;
      }
      if(largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, heap_size, largest);
      }
    }
    void buildMaxHeap(vi& a, int n) {     // O(n)
      rFOR(i, n/2-1, 0){
        maxHeapify(a, n, i);
      }
    }
    void heapSort(vi& a, int n) {     // O(n*log n)
      buildMaxHeap(a, n);
      rFOR(i, n-1, 1) {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
      }
    }
    vi sortArray(vector<int>& nums) {     // TC: O(n*log n), SC: O(log n)
      int n = nums.size();
      // HEAP_SIZE = n;
      heapSort(nums, n);
      return nums;
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vi nums;
    int x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    vi res = sol.sortArray(nums);
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