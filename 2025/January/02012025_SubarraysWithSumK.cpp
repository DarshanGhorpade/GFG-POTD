// Problem link --> https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1
// Difficulty       --> Medium

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> prefixSumCount = { {0, 1} };
        int sum = 0, count = 0;

        for (int num : arr) {
            sum += num;
            count += prefixSumCount[sum - k];
            prefixSumCount[sum]++;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
            << "\n";
    }

    return 0;
}

// } Driver Code Ends