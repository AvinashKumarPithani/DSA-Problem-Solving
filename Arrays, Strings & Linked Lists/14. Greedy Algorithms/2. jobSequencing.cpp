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

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {   // O(n*md)
      int n = profit.size();
      vector<vi> pdi;
      int md = 0;
      FOR(i, 0, n) {
        pdi.pb({profit[i], deadline[i], i+1});
        md = max(md , deadline[i]);
      }
      sort(pdi.begin(), pdi.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0];
      });

      vi job(md, 0);
      int p = 0, x = 0, jobcnt = 0;
      while(x < n && jobcnt < md) {
        rFOR(i, pdi[x][1], 1) {
          if(!job[i-1]) {
            job[i-1] = pdi[x][2];
            p += pdi[x][0];
            jobcnt++;
            break;
          }
        }
        x++;
      }
      return {jobcnt, p};
    }
};

void solve(Solution sol) { 
    string line;
    getline(cin, line); // Read the whole line
    istringstream iss1(line); // Create stream from line
    vi d;
    int x;
    while (iss1 >> x) {     
      d.pb(x); // Extract numbers one by one 
    }

    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, line); // Read the whole line
    istringstream iss2 (line); // Create stream from line
    vi p;
    while (iss2 >> x) {     
      p.pb(x); // Extract numbers one by one 
    }
    vi res = sol.jobSequencing(d, p);
    cout << res[0] << " " << res[1];
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
