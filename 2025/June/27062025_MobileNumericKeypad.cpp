// Problem Link ---> https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1
// Difficulty   ---> Medium

class Solution {
  public:
    int getCount(int n) {
        // code here
        int ans = 0;
        vector<vector<int>> p(4, vector<int>(3, 1)), c(4, vector<int>(3));
        p[3][0] = p[3][2] = 0;
        vector<vector<int>> d = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 3; j++) {
                    if (i==3&&(j==0||j==2)) continue;
                    c[i][j] = 0;
                    for (auto &v : d) {
                        int x = i+v[0], y = j+v[1];
                        if (x>=0 && x<4 && y>=0 && y<3) c[i][j] += p[x][y];
                    }
                }
            p = c;
        }
        for (auto &r : p) for (int v : r) ans += v;
        return ans;
    }
};
