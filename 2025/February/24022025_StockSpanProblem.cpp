// Problem Link ---> https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        vector<int> span(arr.size());
        for (int i = 0; i < arr.size(); i++){
            int spanCount = 1;
            while ((i - spanCount) >= 0 && arr[i - spanCount] <= arr[i]){
                spanCount += span[i - spanCount];
            }
            span[i] = spanCount;
        }
        return span;
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
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
