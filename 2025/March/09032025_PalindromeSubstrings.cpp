// Problem Link ---> https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; --l, ++r) res++;
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) res++;
        }
        return res - n;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
