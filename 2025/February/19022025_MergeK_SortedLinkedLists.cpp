// Problem Link ---> https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Difficulty   ---> Medium

//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if (arr.empty()) return nullptr;
        while (arr.size() > 1) {
            vector<Node*> temp;
            for (int i = 0; i < arr.size(); i += 2) 
                temp.push_back(merge(arr[i], i + 1 < arr.size() ? arr[i + 1] : nullptr));
            arr = temp;
        }
        return arr[0];
    }
    
    Node* merge(Node* a, Node* b) {
        if (!a || !b) return a ? a : b;
        if (a->data > b->data) swap(a, b);
        a->next = merge(a->next, b);
        return a;
    }
};



//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends
