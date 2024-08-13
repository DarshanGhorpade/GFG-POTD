/*
Problem Link ---> https://www.geeksforgeeks.org/problems/square-root/1
Difficulty   ---> Easy
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long int low = 1;
        long long int high = n;
        long long int ans = 0;
        
        while (low <= high) {
            long long int mid = low + (high - low) / 2;
            if (mid * mid == n) {
                return mid;
            }
            if (mid * mid < n) {
                ans = mid;  
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends