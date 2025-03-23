// Problem Link ---> https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &digits) {
        // Code here
        if (digits[0] == '0') return 0;
        int n = digits.size(), prev2 = 1, prev1 = 1;
        for (int i = 1; i < n; i++) {
            int curr = 0;
            if (digits[i] != '0') curr = prev1;
            int num = (digits[i - 1] - '0') * 10 + (digits[i] - '0');
            if (num >= 10 && num <= 26) curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
