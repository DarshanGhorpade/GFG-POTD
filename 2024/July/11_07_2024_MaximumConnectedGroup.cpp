/*
Problem Link ---> https://www.geeksforgeeks.org/problems/maximum-connected-group/1
Difficulty   ---> Hard

You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

Examples :

Input: grid = [1, 1]
             [0, 1]
Output: 4
Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
[1, 1]
[1, 1]
Input: grid = [1, 0, 1]
             [1, 0, 1]
             [1, 0, 1]
Output: 7
Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
[1, 0, 1]
[1, 0, 1]
[1, 1, 1]
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= size of the grid<= 500
0 <= grid[i][j] <= 1
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> dirX={1,0,0,-1};
    vector<int> dirY={0,1,-1,0};
    void dfs(vector<vector<int>> &parent,map<int,int>&mp,int p,int i,int j, vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || parent[i][j]!=-1 || grid[i][j]!=1){
            return;
        }
        parent[i][j]=p;
        mp[p]++;
        for(int k=0;k<4;k++){
            dfs(parent,mp,p,i+dirX[k],j+dirY[k],grid);
        }
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        vector<vector<int>> parent(grid.size(),vector<int>(grid[0].size(),-1));
        map<int,int> mp;
        int p=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && parent[i][j]==-1){
                    dfs(parent,mp,p,i,j,grid);
                    p++;
                }
            }
        }
        
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    set<int> s;
                    int curr=1;
                    for(int k=0;k<4;k++){
                        int x=i+dirX[k];
                        int y=j+dirY[k];
                        if(x>-1 && y>-1 && x<grid.size() && y<grid[0].size()){
                            if(parent[x][y]!=-1 && s.find(parent[x][y])==s.end()){
                                s.insert(parent[x][y]);
                                curr+=mp[parent[x][y]];
                            }
                        }
                    }
                   
                    maxi=max(curr,maxi);
                }
            }
        }
        for(auto &i:mp){
            maxi=max(maxi,i.second);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends
