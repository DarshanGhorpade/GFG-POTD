// Problem Link ---> https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
// Difficulty   ---> Hard

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int l = 0, r = 0, m = 0;
        for (char c : s) {
            if (c == '(') l++;
            else r++;
            if (l == r) m = max(m, 2 * r);
            else if (r > l) l = r = 0;
        }
        l = r = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') l++;
            else r++;
            if (l == r) m = max(m, 2 * l);
            else if (l > r) l = r = 0;
        }
        return m;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
