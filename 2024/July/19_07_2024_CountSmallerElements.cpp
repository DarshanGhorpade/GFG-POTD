/*
Problem Link ---> https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1
Difficulty   ---> Hard

Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
Input: arr[] = [1, 2, 3, 4, 5]
Output: [0, 0, 0, 0, 0]
Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i]  ≤ 108
*/

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    vector<int> seg;
    
    void update(int i, int j, int l, int h){
        if(j < l || j > h)
            return;
        seg[i]++;
        // cout << l <<" "<<h<<" "<<seg[i]<<endl;
        if(l == h)
            return;
        int mid = (l+h)>>1;
        update(2*i + 1, j, l, mid);
        update(2*i + 2, j, mid+1, h);
    }
    
    int query(int i, int j, int l, int h){
        if(h < j)
            return 0;
        if(l >= j)
            return seg[i];
        int mid = (l+h)>>1;
        return query(2*i+1, j, l, mid) +
        query(2*i+2, j, mid+1, h);
    }
    
    vector<int> constructLowerArray(vector<int> &arr) {
    
        int n = arr.size();
        seg.resize(4*n);
        vector<int> ans(n);
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(), temp.end());
        
        for(int i=0;i<n;i++){
            ans[temp[i][1]] = query(0, temp[i][1], 0, n-1);
            update(0,temp[i][1],0,n-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
