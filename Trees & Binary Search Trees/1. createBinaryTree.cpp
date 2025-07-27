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

// https://www.geeksforgeeks.org/problems/binary-tree-representation/1

// User function Template for C++

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

class Solution {
  public:
    void create_tree(node* root0, vector<int>& vec) {
      root0->left = newNode(vec[1]);
      root0->right = newNode(vec[2]);

      root0->left->left = newNode(vec[3]);
      root0->left->right = newNode(vec[4]);

      root0->right->left = newNode(vec[5]);
      root0->right->right = newNode(vec[6]);
    }
};

// Example input format:
// 2
// 1 2 3 4 3 4 5
// 5 56 6 7 8 89
// output:
// 1
// 1

void solve(Solution sol) { 
    string line;
    getline(cin, line); // Read the whole line
    istringstream iss1(line); // Create stream from line
    vi nums;
    int x;
    while (iss1 >> x) {     
      nums.pb(x); // Extract numbers one by one 
    }
    node* root = newNode(nums[0]);
    sol.create_tree(root, nums);
    bool res = true;
    node* temp = root;
    int i = 0;
    queue<node*> q;
    q.push(temp);
    while(!q.empty()) {
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
      if(q.front()->data != nums[i++]) res = false;
      q.pop();
      if(!q.empty()) temp = q.front();
    }
    cout << res;
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