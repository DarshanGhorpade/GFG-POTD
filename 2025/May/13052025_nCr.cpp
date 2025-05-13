// Problem Link ---> https://www.geeksforgeeks.org/problems/ncr1019/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    static const int MOD = 1e9+7;
    long long modexp(long long x, long long y) {
        long long res = 1;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
  public:
    int nCr(int n, int r) {
        // code here
        if (r > n) return 0;
        vector<long long> fact(n+1, 1), inv(n+1);
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
        inv[n] = modexp(fact[n], MOD-2);
        for (int i = n; i > 0; --i)
            inv[i-1] = inv[i] * i % MOD;
        return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
