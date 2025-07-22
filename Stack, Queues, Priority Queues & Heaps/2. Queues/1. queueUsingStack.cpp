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

// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(!s2.empty()) {
            int x = s2.top();
            s2.pop();
            return x;
        }
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(!s2.empty()) return s2.top();
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    bool empty() {
        if(s2.empty() && s1.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

void solve() {
    string line;
    getline(cin, line); // Read the whole line

    istringstream iss(line); // Create stream from line
    vs inp;
    string s;
    int n = 0;
    while (iss >> s) {
      inp.pb(s); // Extract numbers one by one
      if(s == "push") n++;
    }
    vi nums(n);
    FOR(i, 0, n) cin >> nums[i];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(inp[0] != "MyQueue") {
      cout << "The first input method name should be the Constructor name.";
    }
    else {
      int x = 0;
      MyQueue* obj = new MyQueue();
      cout << "null ";
      FOR(i, 1, inp.size()) {
        if(inp[i] == "push") {
          obj->push(nums[x++]);
          cout << "null ";
        }
        else if(inp[i] == "pop") {
          if(obj->empty()) cout << '\n' << "'pop' arguments are invalid: Invalid call to function pop()" << '\n';
          else {
            int param_2 = obj->pop();
            cout << param_2 << " ";
          }
        }
        else if(inp[i] == "peek") {
          if(obj->empty()) cout << '\n' << "'peek' arguments are invalid: Invalid call to function peek()" << '\n';
          int param_3 = obj->peek();
          cout << param_3 << " ";
        }
        else if(inp[i] == "empty") {
          bool param_4 = obj->empty();
          if(param_4) cout << "true ";
          else cout << "false ";
        }
      }
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