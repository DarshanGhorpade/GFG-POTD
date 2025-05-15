// Problem Link ---> https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1
// Difficulty   ---> Easy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        long long cnt[256]={}, ans=0;
        for(char c:s) cnt[(unsigned char)c]++;
        for(int i=0;i<256;i++)
            ans += cnt[i]*(cnt[i]+1)/2;
        return (int)ans;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
