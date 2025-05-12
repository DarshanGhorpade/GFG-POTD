// Problem Link ---> https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1
// Difficulty   ---> Hard

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> avail;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        vector<int> cnt(n);
        for(int i=0;i<n;i++) avail.push(i);
        for(auto &m:meetings){
            long long s=m[0], e=m[1];
            while(!busy.empty() && busy.top().first<=s){
                avail.push(busy.top().second);
                busy.pop();
            }
            int r = avail.empty() ? (busy.top().second) : avail.top();
            if(avail.empty()) {
                long long t=busy.top().first;
                busy.pop();
                busy.push({t+e-s, r});
            } else {
                avail.pop();
                busy.push({e, r});
            }
            cnt[r]++;
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
