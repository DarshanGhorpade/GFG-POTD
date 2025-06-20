//Problem Link ---> https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1
// Difficulty  ---> Medium

class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        map<int, int> m;
        for (int x : arr) m[x]++;
        for (auto& p : m) {
            int v = p.first, f = p.second;
            if (f == 0) continue;
            for (int i = 1; i < k; i++) {
                if (m[v + i] < f) return false;
                m[v + i] -= f;
            }
        }
        return true;
    }
};
