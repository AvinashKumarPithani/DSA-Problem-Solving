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

// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int> h1, h2;
    MedianFinder() {
    
    }
    
    void addNum(int num) {
      h1.push(num);
      int x = h1.top();
      h1.pop();
      h2.push(-x);
      if(h1.size() != h2.size()) {
        x = -h2.top();
        h2.pop();
        h1.push(x);
      }
    }
    
    double findMedian() {
      if(h1.size() == h2.size()) {
        return (h1.top() - h2.top())/ 2.0;
      }
      return h1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Example Input:
// 2
// MedianFinder addNum addNum findMedian addNum findMedian
// 1 2 3
// Expected Output:
// null null null 1.5 null 2

void solve() {      // O(log n) for addNum, O(1) for findMedian
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vs inp;
    string s;
    while (iss >> s) {
        inp.pb(s); // Extract numbers one by one
    }
    
    if(inp[0] != "MedianFinder") {
      cout << "The first input method name should be the Constructor name.";
    }
    else {
      MedianFinder* obj = new MedianFinder();
      cout << "null ";
      FOR(i, 1, inp.size()) {
        if(inp[i] == "addNum") {
          int x;
          cin >> x;
          obj->addNum(x);
          cout << "null ";
        } else if(inp[i] == "findMedian") {
          cout << obj->findMedian() << " ";
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