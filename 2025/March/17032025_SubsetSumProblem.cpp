// Problem Link ---> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Difficulty   ---> Medium

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& num, int k) {
        // code here
        int n = num.size();
        vector<int> prev(k + 1, 0);
        prev[0] = 1;
        if (num[0] <= k) {
            prev[num[0]] = 1;
        }
        for (int ind = 1; ind < n; ind++) {
            vector<int> cur(k + 1, 0);
            cur[0] = 1;
            for (int target = 1; target <= k; target++) {
                int notTaken = prev[target];

                int taken = 0;
                if (num[ind] <= target) {
                    taken = prev[target - num[ind]];
                }

                cur[target] = notTaken + taken;
            }
            prev = cur;
        }
        return prev[k];
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
