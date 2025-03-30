// Problem Link ---> https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1
// Difficulty   ---> Easy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int cnt = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++)
           mp[s[i]] = i;
      
        int ans = -1;
        for(int i = 0; i < n; i++) {
            ans = fmax(ans, mp[s[i]]);
            
            if(ans == i)
                cnt++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
