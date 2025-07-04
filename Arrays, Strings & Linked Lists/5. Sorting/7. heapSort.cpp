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

class Solution {
  public:
    int HEAP_SIZE;
    void maxHeapify(vll& a, int i) {   // O(log n)
      int l = 2*i + 1;
      int r = 2*i + 2;
      int largest = i;
      if(l < HEAP_SIZE && a[l] > a[largest]) {
        largest = l;
      }
      if(r < HEAP_SIZE && a[r] > a[largest]) {
        largest = r;
      }
      if(largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, largest);
      }
    }
    void buildMaxHeap(vll& a) {     // O(n)
      int n = a.size();
      rFOR(i, n/2-1, 0){
        maxHeapify(a, i);
      }
    }
    void heapSort(vll& a, int n) {     // O(n*log n)
      buildMaxHeap(a);
      rFOR(i, n-1, 1) {
        swap(a[0], a[i]);
        HEAP_SIZE--;
        maxHeapify(a, 0);
      }
    }
    void sortIt(vector<long long>& arr) {     // TC: O(n*log n), SC: O(1)
      int n = arr.size();
      HEAP_SIZE = n;
      heapSort(arr, n);
    }
};

void solve(Solution sol) {
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vll nums;
    ll x;
    while (iss >> x) {
      nums.pb(x); // Extract numbers one by one
    }
    sol.sortIt(nums);
    for(auto i: nums) {
      cout << i << " ";
    }
}

int main() {
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