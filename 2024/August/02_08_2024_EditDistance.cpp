/*
Problem Link ---> https://www.geeksforgeeks.org/problems/edit-distance3702/1
Difficulty   ---> Hard

Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ str1.length(), str2.length() ≤ 100
Both the strings are in lowercase.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
        // Code here
        int m = str1.size();
        int n = str2.size();
        
        // Creating a 2D Vector DP 
         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // Iterating through words
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                // If i == 0, i.e STR1 is empty, meaning it will require j number of insertions
                if(i == 0){
                    dp[i][j] = j;
                }
                
                // If j == 0; i.e STR2 is empty, meaning it will require i number of deletions
                else if(j == 0){
                    dp[i][j] = i;
                }
                
                // We got the same word, so we'll do nothing and take back the result of previous
                else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                
                // Word isn't matching so we'll take minimum of insertion, removal or replacement
                else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        
        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
