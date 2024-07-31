/*
Problem Link ---> https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 
Difficulty   ---> Medium

Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    map<pair<int, int>, char> mp;

    void dfs(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& vis, vector<string>& res, string path) {
        int n = mat.size();
        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            return;
        }
        vis[i][j] = 1;
        for (auto dir : dirs) {
            int x = dir[0] + i;
            int y = dir[1] + j;

            if (x < 0 || y < 0 || x >= n || y >= n || vis[x][y] || mat[x][y] == 0)
                continue;

            dfs(mat, x, y, vis, res, path + mp[{dir[0], dir[1]}]);
        }
        vis[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        mp[{0, 1}] = 'R';
        mp[{1, 0}] = 'D';
        mp[{-1, 0}] = 'U';
        mp[{0, -1}] = 'L';

        int n = mat.size();
        vector<string> res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (mat[0][0] == 1) {
            dfs(mat, 0, 0, vis, res, "");
        }
        sort(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
