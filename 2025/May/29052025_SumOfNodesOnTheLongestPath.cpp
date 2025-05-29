// Problem Link ---> https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// Difficulty   ---> Medium

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  private:
  pair<int, int> dfs(Node* root) {
        if (!root) return {0, 0};
        auto l = dfs(root->left), r = dfs(root->right);
        if (l.first > r.first) return {l.first + 1, l.second + root->data};
        if (r.first > l.first) return {r.first + 1, r.second + root->data};
        return {l.first + 1, max(l.second, r.second) + root->data};
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return dfs(root).second;
    }
};
