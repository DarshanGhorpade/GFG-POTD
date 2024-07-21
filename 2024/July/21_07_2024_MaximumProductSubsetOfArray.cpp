/*
Problem Link ---> https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1
Difficulty   ---> Medium

Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 2 * 104
-10 <= arr[i] <= 10
*/

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int mod = 1000000007;
        int zero = 0;//zero flag
        int pos = 0; //positive flag
        int neg = 0; //negative number count
        int maxNeg = INT_MIN; //maximum negative count
        long long int posPro = 1; //keep track of product of negative numbers
        long long int negPro = 1; //keep track of product of positive numbers
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0){
                zero = 1;
            }
            else if(arr[i] < 0){
                neg++;
                negPro = (negPro*arr[i])%mod;
                maxNeg = max(maxNeg, arr[i]);
            }
            else{
                pos = 1;
                posPro =(posPro*arr[i])%mod;
            }
        }
        
        if(pos == 0 && neg <= 1 && zero == 1) return 0;
        if(pos==1){
            if(neg%2 == 0){ //if negative numbers are in even then the product will be posiitve
                posPro = (posPro*negPro)%mod;
            }
            else if(neg%2!=0){//product will be negative
                posPro = (posPro*negPro/maxNeg)%mod ; // dividimg the maximum negative number to make the product positive
            }
            return posPro%mod;
        }
        if(pos==0 && neg > 1){
             if(neg%2!=0){
                negPro = (negPro/maxNeg)%mod ;
            }
            return negPro%mod;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
