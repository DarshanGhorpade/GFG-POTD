// Problem Link --> https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Difficulty        --> Hard

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxWater(vector<int>& arr) {
        // code here
        int l = 0, r = arr.size() - 1, res = 0, lMax = 0, rMax = 0;
        while (l < r) {
            arr[l] < arr[r] ? (lMax = max(lMax, arr[l]), res += lMax - arr[l++]) : (rMax = max(rMax, arr[r]), res += rMax - arr[r--]);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends