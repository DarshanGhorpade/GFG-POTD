// Problem Link ---> https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    stack<long long> s;
    long long minVal;
  public:
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if (s.empty()) { minVal = x; s.push(x); }
        else if (x >= minVal) s.push(x);
        else { s.push(2LL * x - minVal); minVal = x; }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
       if (s.empty()) return;
        if (s.top() < minVal) minVal = 2 * minVal - s.top();
        s.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return s.empty() ? -1 : (s.top() < minVal ? minVal : s.top());
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return s.empty() ? -1 : minVal;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
