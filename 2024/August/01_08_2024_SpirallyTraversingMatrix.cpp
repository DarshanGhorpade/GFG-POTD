/*
Problem Link ---> https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
Difficulty   ---> Medium

You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= matrix.size(), matrix[0].size() <= 100
0 <= matrix[i][j]<= 100
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        int n = matrix.size(), m = matrix[0].size();
        int dxy[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        bool vis[n+1][m+1]; memset(vis,false,sizeof(vis));
        vector<int> res;
        int i = 0, j = 0, k = 0;
        while ( true ){
            res.push_back(matrix[i][j]); vis[i][j] = true;
            if ( res.size() == n*m ) break;
            int ni = i + dxy[k%4][0], nj = j + dxy[k%4][1];
            if ( !(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj]) ) k++;
            i += dxy[k%4][0]; j += dxy[k%4][1];
        } return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
