// Problem Link ---> https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1
// Difficulty   ---> Easy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& x) {
        // code here
        string s;
        s=x;
        stack<int> st;
        
        for(int i=0;i<s.length();i++)
        {
            if(st.size()==0 && (s[i]==')'|| s[i]=='}' || s[i]==']'))
            return false;
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{' )
                || s[i]==']' && st.top()=='[' )
                st.pop();
                
                else if((s[i]==')' && st.top()!='(') || (s[i]=='}' && st.top()!='{' )
                || s[i]==']' && st.top()!='[' )
                return false;
            
        }
        if(st.size()!=0)
        return false;
        else
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
