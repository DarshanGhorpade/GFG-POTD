// Problem Link ---> https://www.geeksforgeeks.org/problems/find-length-of-loop/1
// Difficulty   ---> Easy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int countNodes(struct Node *n)  
    {  
        int res = 1;  
        struct Node *temp = n;  
        while (temp->next != n)  
        {  
            res++;  
            temp = temp->next;  
        }  
        return res;  
    } 
    
    int countNodesinLoop(struct Node *head)
    {
        if(head == NULL)
            return 0 ;
        Node *slow = head;
        Node *fast = head;
        while(slow &&  fast && fast->next)
        {
            fast = fast->next ->next; 
            slow = slow->next;
            if(slow == fast)
                return countNodes(slow);
        }        
        return 0;
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
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
