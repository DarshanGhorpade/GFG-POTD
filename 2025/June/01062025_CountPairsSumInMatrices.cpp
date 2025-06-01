// Problem Link ---> https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1
// Difficulty   ---> Easy

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
    
        vector<int> v1, v2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v1.push_back(mat1[i][j]);
                v2.push_back(mat2[i][j]);
            }
        }
        
        int count = 0;
        
        int i = 0;
        int j = v2.size() - 1;
        
        while(i < v1.size() && j >= 0) {
            int sum = v1[i] + v2[j];
            if(sum == x) {
                count++;
                i++;
                j--;
            } else if(sum < x) {
                i++;
            } else {
                j--;
            }
        }
        
        return count;
    }
};
