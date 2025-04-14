// Problem Link ---> https://www.geeksforgeeks.org/problems/alien-dictionary/1
// Difficulty   ---> Hard

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> g(26);
        vector<int> in(26), seen(26);
        for (auto &s : words) for (char c : s) seen[c - 'a'] = 1;
        for (int i = 0; i < words.size() - 1; i++) {
            string &a = words[i], &b = words[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j]) j++;
            if (j == n && a.size() > b.size()) return "";
            if (j < n) g[a[j] - 'a'].push_back(b[j] - 'a'), in[b[j] - 'a']++;
        }
        queue<int> q;
        for (int i = 0; i < 26; i++) if (seen[i] && !in[i]) q.push(i);
        string res;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res += u + 'a';
            for (int v : g[u]) if (--in[v] == 0) q.push(v);
        }
        for (int i = 0; i < 26; i++) if (seen[i] && in[i]) return "";
        return res;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
