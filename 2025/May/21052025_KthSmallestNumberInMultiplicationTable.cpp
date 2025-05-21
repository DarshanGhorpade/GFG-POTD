// Problem Link ---> https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1
// Difficulty   ---> Hard

class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        int l = 1, r = m * n;
        while (l < r) {
            int mid = (l + r) / 2, cnt = 0;
            for (int i = 1; i <= m; ++i) cnt += min(n, mid / i);
            cnt < k ? l = mid + 1 : r = mid;
        }
        return l;
    }
};
