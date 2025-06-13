// Problem Link ---> https://www.geeksforgeeks.org/problems/koko-eating-bananas/1
// Difficulty   ---> Medium

class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int lo = 1, hi = *max_element(arr.begin(), arr.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int hours = 0;
            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
            }
            if (hours <= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
