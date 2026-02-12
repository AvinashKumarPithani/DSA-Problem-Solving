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

// https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
int gcd(int a, int b){      // O(log(min(a,b)))
    if(b==0) return a;
    return gcd(b,a%b);
}
string gcdOfStrings(string str1, string str2) {     // O(n1+n2) to check if str1+str2 == str2+str1 + O(log(min(n1,n2))) to find gcd of lengths + O(gcd(n1, n2)) to find substring
    if(str1+str2 == str2+str1){
        int n1 = str1.length();
        int n2 = str2.length();
        
        return str1.substr(0,gcd(n1, n2));
    }
    else{
        return "";
    }
}
void solve() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << gcdOfStrings(str1, str2);
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