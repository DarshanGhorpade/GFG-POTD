// Problem Link ---> https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1
// Difficulty   ---> Medium

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string res = "1";
        for (int i = 1; i < n; ++i) {
            string temp;
            for (int j = 0; j < res.size(); ) {
                int k = j;
                while (k < res.size() && res[k] == res[j]) ++k;
                temp += to_string(k - j) + res[j];
                j = k;
            }
            res = temp;
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
