// Problem Link ---> https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
// Difficulty   ---> Hard

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            left[i] = s.empty() ? 0 : s.top() + 1;
            s.push(i);
        }
        
        while (!s.empty()) s.pop();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            right[i] = s.empty() ? n - 1 : s.top() - 1;
            s.push(i);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) 
            res = max(res, arr[i] * (right[i] - left[i] + 1));
        
        return res;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
