// Problem Link ---> https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1
// Difficulty   ---> Medium

class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        unordered_set<int> s;
        for (int& x : arr) s.insert(x * x);
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
                if (s.count(arr[i]*arr[i] + arr[j]*arr[j])) return true;
        return false;
    }
};
