// Problem Link ---> https://www.geeksforgeeks.org/problems/smallest-divisor/1
// Difficulty   ---> Medium

class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int l = 1, h = *max_element(arr.begin(), arr.end()), n = arr.size();
        while (l < h) {
            int m = l + (h - l) / 2, s = 0;
            for (int i = 0; i < n; ++i)
                s += (arr[i] + m - 1) / m;
            if (s <= k) h = m;
            else l = m + 1;
        }
        return l;
    }
};
