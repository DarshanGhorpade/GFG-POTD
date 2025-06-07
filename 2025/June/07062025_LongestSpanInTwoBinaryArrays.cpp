// Problem Link ---> https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1
// Difficulty   ---> Medium

class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here.
        int n = arr1.size(), res = 0;
        unordered_map<int, int> diffMap;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += arr1[i];
            sum2 += arr2[i];
            int diff = sum1 - sum2;
            if (diff == 0) res = i + 1;
            else if (diffMap.count(diff)) res = max(res, i - diffMap[diff]);
            else diffMap[diff] = i;
        }
        return res;
    }
};
