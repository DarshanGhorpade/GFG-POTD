// Problem Link ---> https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1
// Difficulty   ---> Medium

class Solution {
    int count(string &s, int k) {
        int n = s.length(), ans = 0;
        vector<int> freq(26, 0);
        int i = 0, distinct = 0;
        for (int j = 0; j < n; ++j) {
            if (++freq[s[j] - 'a'] == 1) ++distinct;
            while (distinct > k)
                if (--freq[s[i++] - 'a'] == 0) --distinct;
            ans += j - i + 1;
        }
        return ans;
    }
  public:
    int countSubstr(string& s, int k) {
        // code here.
        return count(s, k) - count(s, k - 1);
    }
};
