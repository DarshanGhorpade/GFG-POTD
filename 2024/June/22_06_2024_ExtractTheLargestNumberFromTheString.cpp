/*
Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

Note: Numbers and words are separated by spaces only. It is guaranteed that there are no leading zeroes in the answer.

Examples :

Input: sentence="This is alpha 5057 and 97"
Output: 5057
Explanation: 5057 is the only number that does not have a 9.
Input: sentence="Another input 9007"
Output: -1
Explanation: Since there is no number that does not contain a 9,output is -1.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(n)

Constraints:
1<=n<=106
1<=answer<=1018

n is the length of a given sentence.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        // code here
        int n = sentence.size();
       stringstream ss(sentence);
       string word;
       long long int maxi = -1;
       while(ss >> word){
           if(word[0]>='1' && word[word.size() - 1] <='8'){
               bool c = 0;
               for(int i = 0;i < word.size(); i++){
                   if(word[i] == '9') c = 1;
               }
               if(!c) {
                   long long d = stoll(word);
                   if(d > maxi) maxi = d;
               }
           }
       }
       return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
