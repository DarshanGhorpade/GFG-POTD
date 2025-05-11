// Problem Link ---> https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        vector<int> p(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i) p[i + 1] = p[i] + arr[i];
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j <= arr.size(); ++j) {
                q.push(p[j] - p[i]);
                if (q.size() > k) q.pop();
            }
        return q.top();
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
