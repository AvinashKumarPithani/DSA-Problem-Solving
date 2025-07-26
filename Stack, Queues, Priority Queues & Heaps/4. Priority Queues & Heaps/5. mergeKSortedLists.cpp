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

// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& v) {
      int n = v.size();
      if(n == 0) return nullptr;
      priority_queue<pair<int, ListNode*>> pq;    
      FOR(i, 0, n) {
        if(v[i]) pq.push({-(v[i]->val), v[i]});
      }
      if(pq.empty()) return nullptr;
      ListNode* ans = new ListNode();
      ListNode* temp = ans;
      while(!pq.empty()) {
        temp->next = new ListNode(-pq.top().first);
        temp = temp->next;
        ListNode* x = pq.top().second;
        pq.pop();
        if(x->next) pq.push({-x->next->val, x->next});
      }
      return ans->next;
    }
};

// Example input format:
// 2           // number of test cases
// 1 2 3 # 4 5 # 6 7    // first test case: three lists [1,2,3], [4,5], and [6,7]
// 1 # 1 2 # 2 3        // second test case: three lists [1], [1,2], and [2,3]

void solve(Solution sol) {    // O(n log k) where n is the total number of elements and k is the number of lists
    string line;
    getline(cin, line); // Read the whole line
    istringstream iss(line); // Create stream from line
    vector<vi> lists;
    vi curr;
    string x;
    
    while(iss >> x) {
      if(x == "#") {  // Use # as delimiter between lists
        lists.pb(curr);
        curr.clear();
      }
      else {
        curr.pb(stoi(x));
      }
    }
    if(!curr.empty()) {
      lists.pb(curr);
    }

    // Convert vector<vector<int>> to vector<ListNode*>
    vector<ListNode*> linkedLists;
    for(const auto& list : lists) {
      if(list.empty()) {
        linkedLists.pb(nullptr);
        continue;
      }
      
      ListNode* dummy = new ListNode();
      ListNode* curr = dummy;
      for(int val : list) {
        curr->next = new ListNode(val);
        curr = curr->next;
      }
      linkedLists.pb(dummy->next);
    }

    // Call mergeKLists and print result
    ListNode* result = sol.mergeKLists(linkedLists);
    
    // Print the merged list
    while(result) {
      cout << result->val << " ";
      result = result->next;
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

