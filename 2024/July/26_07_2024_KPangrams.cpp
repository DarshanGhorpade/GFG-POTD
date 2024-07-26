/*
Problem Link ---> https://www.geeksforgeeks.org/problems/k-pangrams0909/1
Difficulty   ---> Easy

Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.

Examples :

Input: str = "the quick brown fox jumps over the lazy dog", k = 0
Output: true
Explanation: the sentence contains all 26 characters and is already a pangram.
Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25 
Output: true
Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.
Input: str = "a b c d e f g h i j k l m", k = 20
Output: false
Explanation: Since there are only 13 alphabetic characters in this case, no amount of swapping can produce a panagram here.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)  

Constraints:
1<= str.size() <= 105
0<= k <= 50
str may contain duplicate characters
str contains only lowercase alphabets or spaces.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool kPangram(string str, int k) {
        // code here
        unordered_map<char, int> m;
        int extra = 0;
        
        // calculate the characters present in excess
        for(int i = 0; i < str.size(); i++){
            if(!isalpha(str[i]))  continue;
            if(m[str[i]] == 1)  extra++;
            else m[str[i]] = 1;
        }
        
        // calculate the total characters brought in str from alphabets
        int t = 0;
        for(char ch = 'a'; ch <= 'z'; ch++){
            if(extra == 0)  break;
            if(m[ch] == 0 && extra > 0){
                m[ch] = 1;
                extra--;
                t++;
            }
        }
        
        // check if all the conditions satisfied
        for(char cc = 'a'; cc <= 'z'; cc++){
            if(m[cc] == 0)  return false;
        }
        if(t<=k)  return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
