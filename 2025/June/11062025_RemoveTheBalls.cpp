// Problem Link ---> https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1
// Difficulty   ---> Medium

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        int n = color.size(), j = -1;
        for (int i = 0; i < n; ++i) {
            if (j >= 0 && color[i] == color[j] && radius[i] == radius[j])
                --j;
            else {
                ++j;
                color[j] = color[i];
                radius[j] = radius[i];
            }
        }
        return j + 1;
    }
};
