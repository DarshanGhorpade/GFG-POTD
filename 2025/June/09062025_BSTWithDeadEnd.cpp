// Problem Link ---> https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1
// Difficulty   ---> Medium

/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
    bool dfs(Node* root, int l, int r) {
        if (!root) return false;
        if (!root->left && !root->right && l == r) return true;
        return dfs(root->left, l, root->data - 1) || dfs(root->right, root->data + 1, r);
    }
  public:
    bool isDeadEnd(Node *root) {
        // Code here
        return dfs(root, 1, INT_MAX);
    }
};
