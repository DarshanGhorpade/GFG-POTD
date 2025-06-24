// Problem Link ---> https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1
// Difficulty   ---> Medium

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.length(), toRemove = k;
        string res;
        for (char c : s) {
            while (!res.empty() && toRemove && res.back() < c) {
                res.pop_back();
                toRemove--;
            }
            res += c;
        }
        res.resize(n - k);
        return res;
    }
};
