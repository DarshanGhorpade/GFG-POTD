// Problem Link ---> https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1
// Difficulty   ---> Medium

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &a) {
        // code here
        int max_xor = 0, mask = 0;
        unordered_set<int> s;
        for(int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            s.clear();
            int temp = max_xor | (1 << i);
            for(int num : a) {
                int prefix = num & mask;
                if(s.count(temp ^ prefix)) { max_xor = temp; break; }
                s.insert(prefix);
            }
        }
        return max_xor;
    }
};





//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
