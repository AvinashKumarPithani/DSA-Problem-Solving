//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// https://www.geeksforgeeks.org/problems/lcm-of-given-array-elements3919/1

class Solution {
  public:
    const int M = 1000000007;
    int gcd(int a, int b){    // O(log(min(a,b)))
        if(b==0) return a;
        return gcd(b, a%b);
    }
    int lcmOfArray(int N , int a[]) {   // O(N*log(maxi)) where maxi is the maximum element in the array
        // code here
        long long x = (a[0]*a[1]/gcd(a[0],a[1]) )%M;
        for(int i=2; i<N; i++){
            x = (x*a[i]/gcd(x, a[i]))%M;
        }
        return x;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout<<ob.lcmOfArray(N,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends