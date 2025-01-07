// Problem link --> https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1
// Difficulty       --> Easy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        // Complete the function
        unordered_map<int, int> freq;
        int res = 0;

        for (int num : arr) {
            int complement = target - num;
            if (freq.count(complement))
                res += freq[complement];

            freq[num]++;
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends