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

// https://leetcode.com/problems/linked-list-cycle

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(!head || !head->next) return false;
      ListNode *p = head;
      ListNode *q = head;
      do {
        p = p->next->next;
        q = q->next;
      } while(p && p->next && p != q);
      if(p == q) return true;
      return false;
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
    if (nums.empty()) return;
    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;
    int i = 1;
    while(i < nums.size()){
      p->next = new ListNode(nums[i]);
      p = p->next;
      i++;
    }
    int pos;
    cin >> pos;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(pos >= 0) {
      ListNode *t = head;
      while(t && pos--) {
        t = t->next;
      }
      p->next = t;
    }
    
    if(sol.hasCycle(head)) cout << "true";
    else cout << "false";
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