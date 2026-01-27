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
string md(string a, string b){      // O(m^2)
    int n = b.length();
    int m = a.length();
    while((a.size())>=(b.size()) && a.substr(0,n)==b){
        a = a.substr(n, a.size());
    }
    return a;
}
string fun(string a, string b){     // O(m^2)
    if(b == "") return a;
    string x = md(a, b);
    if((x.size()) >= (b.size())){
        return "";
    }
    return fun(b, x);
}
string gcdOfStrings(string str1, string str2) {
    if((str1.size())>(str2.size())){
        return fun(str1, str2);
    }
    else{
        return fun(str2, str1);
    };
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