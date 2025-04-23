// Problem Link ---> https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& A) {
        // Code here.
        int x = 0, a = 0, b = 0;
        for (int n : A) x ^= n;
        for (int n : A) (n & (x & -x) ? a : b) ^= n;
        return a < b ? vector<int>{a, b} : vector<int>{b, a};
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
