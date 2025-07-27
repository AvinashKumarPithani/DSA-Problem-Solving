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

// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      vector<vi> ans;
      if(!root) return ans;    
      queue<Node*> q;
      q.push(root);
      Node* dummyNode = new Node(-1);
      q.push(dummyNode);
      vi v;
      while(!q.empty()) {
        Node* t = q.front();
        q.pop();
        if(t->val != -1) {
          v.pb(t->val);
          for(auto &i: t->children) {
            q.push(i);
          }
        }
        else {
          ans.pb(v);
          v.clear();
          if(!q.empty()) q.push(dummyNode);
        }
      }
      return ans;
    }
};

// Example Input:
// 2
// 1 null 3 2 4 null 5 6
// 1 null 2 3 4 5 null null 6 7 null 8 null 9 10 null null 11 null 12 null 13 null null 14
// Output:
// 1
// 3 2 4
// 5 6

// 1
// 2 3 4 5
// 6 7 8 9 10
// 11 12 13
// 14


void solve(Solution sol) { 
    string line;
    getline(cin, line); // Read the whole line
    istringstream iss1(line); // Create stream from line
    vi nums;
    string x;
    while (iss1 >> x) {
      if(x != "null") nums.pb(stoi(x)); // Extract numbers one by one
      else nums.pb(-1); // Use -1 to represent null
    }
    if (nums.empty()) return; // If no numbers, return
    if (nums[0] == -1) return; // If the first number is null, return
    queue<Node*> q;
    Node* root = new Node(nums[0]);
    q.push(root);
    int i = 2;
    while(i < nums.size() && !q.empty()) {
      Node* current = q.front();
      q.pop();
      
      // Process all children of current node until we hit a null
      while(i < nums.size() && nums[i] != -1) {
        Node* child = new Node(nums[i]);
        current->children.push_back(child);
        q.push(child);
        i++;
      }
      i++; // Skip the null
    }
    vector<vi> res = sol.levelOrder(root);
    for (const auto& level : res) {
      FOR(i, 0, level.size()) {
        cout << level[i];
        if (i < level.size() - 1) cout << " ";
      }
      cout << '\n';
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