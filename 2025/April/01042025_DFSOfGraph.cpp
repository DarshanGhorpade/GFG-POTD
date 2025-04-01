// Problem Link ---> https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Difficulty   ---> Easy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& result, vector<bool>& visited){
        visited[node] = true;
        result.push_back(node);
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour])
                dfsHelper(neighbour, adj, result, visited);
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> result;
        vector<bool> visited(n,false);
        
        dfsHelper(0, adj, result, visited);
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
