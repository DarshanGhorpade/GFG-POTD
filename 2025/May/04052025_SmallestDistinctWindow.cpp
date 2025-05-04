// Problem Link ---> https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n = str.size();

        // Get the total number of distinct characters in str
        unordered_set<char> uniqueChars(str.begin(), str.end());
        int totalUnique = uniqueChars.size();

        // Hash map to store the frequency of characters in current window
        unordered_map<char, int> windowFreq;

        int minLength = n + 1;
        int left = 0;
        int count = 0;

        for (int right = 0; right < n; ++right) {
            windowFreq[str[right]]++;

            // Only increase count when a new character from unique set is fully included
            if (windowFreq[str[right]] == 1) {
                count++;
            }

            // Try to minimize the window
            while (count == totalUnique) {
                minLength = min(minLength, right - left + 1);

                // Try to shrink the window
                windowFreq[str[left]]--;
                if (windowFreq[str[left]] == 0) {
                    count--;
                }
                left++;
            }
        }

        return minLength;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
