// Problem Link ---> https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        // your code here
        int a = 0, b = 1, c = 0;
        for(int i = 0; i < n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
