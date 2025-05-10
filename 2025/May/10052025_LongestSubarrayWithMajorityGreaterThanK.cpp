// Problem Link ---> https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        vector<int> transformed(n);
        
        // Step 1: Transform the array
        for (int i = 0; i < n; i++) {
            transformed[i] = (arr[i] > k) ? 1 : -1;
        }
        
        // Step 2: Track prefix sums and first occurrences
        unordered_map<int, int> firstIndex;
        int prefixSum = 0;
        int maxLen = 0;
    
        for (int i = 0; i < n; i++) {
            prefixSum += transformed[i];
            
            if (prefixSum > 0) {
                maxLen = i + 1;  // whole array from 0 to i has positive sum
            } else {
                // check if (prefixSum - 1) has occurred before
                if (firstIndex.find(prefixSum - 1) != firstIndex.end()) {
                    maxLen = max(maxLen, i - firstIndex[prefixSum - 1]);
                }
            }
            
            // Store first occurrence of this prefixSum
            if (firstIndex.find(prefixSum) == firstIndex.end()) {
                firstIndex[prefixSum] = i;
            }
        }
        
        return maxLen;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
