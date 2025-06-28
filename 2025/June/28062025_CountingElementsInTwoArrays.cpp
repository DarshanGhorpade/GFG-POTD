// Problem Link ---> https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1
// Difficulty   ---> Medium

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size(), mx = *max_element(b.begin(), b.end());
        vector<int> res(n), cnt(mx + 1);
        for (int x : b) cnt[x]++;
        for (int i = 1; i <= mx; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++) res[i] = cnt[min(a[i], mx)];
        return res;
    }
};
