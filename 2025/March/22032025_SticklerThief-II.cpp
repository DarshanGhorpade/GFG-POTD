// Problem Link ---> https://www.geeksforgeeks.org/problems/house-robber-ii/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        if (n == 1) return arr[0];

        auto robRange = [&](int l, int r) {
            int prev2 = 0, prev1 = 0;
            for (int i = l; i <= r; i++) {
                int curr = max(prev1, prev2 + arr[i]);
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        };

        return max(robRange(0, n - 2), robRange(1, n - 1));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
