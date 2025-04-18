// Problem Link ---> https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1
// Difficulty   ---> Medium

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Trie {
  public:
    set<string> words;
    Trie() {
        // implement Trie
    }

    void insert(string &word) {
        // insert word into Trie
        words.insert(word);
    }

    bool search(string &word) {
        // search word in the Trie
        return words.find(word)!=words.end();
    }

    bool isPrefix(string &prefix) {
        // search prefix word in the Trie
        for(set<string>::iterator it = words.begin(); it!=words.end(); it++){
            if((*it).rfind(prefix, 0) == 0) return true;
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
