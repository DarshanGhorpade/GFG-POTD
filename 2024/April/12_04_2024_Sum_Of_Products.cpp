//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long ans = 0;
        /*
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                ans += arr[i] & arr[j];
            }
        }
        */
        for (int i = 0; i < 32; i++) {
        // Count number of elements with i'th bit set
        long long k = 0; // Initialize the count
        for (int j = 0; j < n; j++)
            if ((arr[j] & (1 << i)))
                k++;
 
        // There are k set bits, means k(k-1)/2 pairs.
        // Every pair adds 2^i to the answer. Therefore,
        // we add "2^i * [k*(k-1)/2]" to the answer.
        ans += (1 << i) * (k * (k - 1) / 2);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
