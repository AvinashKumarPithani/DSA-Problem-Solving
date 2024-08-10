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

// https://leetcode.com/problems/find-greatest-common-divisor-of-array/

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int findGCD(vector<int>& nums) {
    int n = nums.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        if(nums[i]>maxi) maxi = nums[i];
        if(nums[i]<mini) mini = nums[i];
    }
    return gcd(maxi, mini);
}

void solve() {
    int n;
    cin >> n;
    vi nums;
    FOR(i, 0, n){
        int x;
        cin >> x;
        nums.pb(x);
    }
    cout << findGCD(nums);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        cout << '\n';
    }
    return 0;
}