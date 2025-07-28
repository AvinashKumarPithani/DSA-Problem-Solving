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

// https://leetcode.com/problems/binary-tree-right-side-view/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void trav(TreeNode* t, vi &ans, int &md, int l) {
      if(!t) return;
      if(l > md) {
        ans.pb(t->val);
        md = l;
      }
      trav(t->right, ans, md, l+1);
      trav(t->left, ans, md, l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
      vi ans;
      int md = 0;
      trav(root, ans, md, 1);
      return ans;
    }
};

// Example Input:
// 2
// 1 2 3 null 5 null 4
// 1 2 3 4 null null null 5

// Output:
// 1 3 4
// 1 3 4 5

void solve(Solution sol) {    // O(N) time and O(N) space, where N is the number of nodes in the tree
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
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nums[0]);
    q.push(root);
    int i = 1;
    while(i < nums.size() && !q.empty()) {
      TreeNode* current = q.front();
      q.pop();
      if (nums[i] != -1) {
        current->left = new TreeNode(nums[i]);
        q.push(current->left);
      }
      i++;
      if (i < nums.size() && nums[i] != -1) {
        current->right = new TreeNode(nums[i]);
        q.push(current->right);
      }
      i++;
    }
    vector<int> res = sol.rightSideView(root);
    FOR(i, 0, res.size()) {
        cout << res[i];
        if (i < res.size() - 1) cout << " "; 
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