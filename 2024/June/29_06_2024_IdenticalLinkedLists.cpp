/*
Problem Link ---> https://www.geeksforgeeks.org/problems/identical-linked-lists/1
Difficulty ---> Basic
Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false. 

Examples:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: false
Explanation:

As shown in figure linkedlists are not identical.
Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: true
Explanation: 
 
As shown in figure both are identical.
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
1 <= length of lists <= 103
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

bool areIdentical(struct Node *head1, struct Node *head2);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2, tmp, d1, d2;
        struct Node *head1 = NULL, *tail1 = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n1;
        cin >> d1;
        head1 = new Node(d1);
        tail1 = head1;
        while (n1-- > 1) {
            cin >> tmp;
            tail1->next = new Node(tmp);
            tail1 = tail1->next;
        }
        cin >> n2;
        cin >> d2;
        head2 = new Node(d2);
        tail2 = head2;
        while (n2-- > 1) {
            cin >> tmp;
            tail2->next = new Node(tmp);
            tail2 = tail2->next;
        }

        areIdentical(head1, head2) ? cout << "true" << endl : cout << "false" << endl;
    }
    return 0;
}

// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to check whether two linked lists are identical or not.
bool areIdentical(struct Node *head1, struct Node *head2) {
    // Code here
    if(head1 == NULL && head2 == NULL){
        return true;
    }
    if(head1 != NULL && head2 == NULL){
        return false;
    }
    if(head1 == NULL && head2 != NULL){
        return false;
    }
    
    bool left = areIdentical(head1->next, head2->next);
    
    bool val = head1->data == head2->data;
    
    if(left && val){
        return true;
    }
    else{
        return false;
    }
}
