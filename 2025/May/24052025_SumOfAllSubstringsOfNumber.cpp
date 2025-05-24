// Problem Link ---> https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
// Difficulty   ---> Medium

class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        long long res=0,f=0;
        for(int i=0;i<s.size();++i){
            f=f*10+(s[i]-'0')*(i+1);
            res+=f;
        }
        return (int)res;
    }
};
