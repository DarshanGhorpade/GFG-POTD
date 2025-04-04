// Problem Link ---> https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> p(V, -1);
        function<int(int)> f = [&](int x){ return p[x] < 0 ? x : p[x] = f(p[x]); };
        for(auto &e : edges){
            int a = f(e[0]), b = f(e[1]);
            if(a == b) return true;
            if(p[a] > p[b]) swap(a, b);
            p[a] += p[b]; p[b] = a;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
