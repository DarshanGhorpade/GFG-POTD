//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //create a set to store unique elements
        std::set<int> s;
        
        //initialize pointers to both arrays
        int l = 0; //pointer to arr1
        int r = 0; //pointer to arr2
        
        //traverse both arrays
        while(l < n && r < m){
            //if elements are equal, insert into set and move both pointers
            if(arr1[l] == arr2[r]){
                s.insert(arr1[l]);
                l++;
                r++;
            }
            //if element in array arr1 is smaller, insert into set and move pointer for arr1
            else if(arr1[l] < arr2[r]){
                s.insert(arr1[l]);
                l++;
            }
            //if element in array arr2 is smaller, insert into set and move pointer for arr2
            else {
                s.insert(arr2[r]);
                r++;
            }
        }
        
        // If there are remaining elements in array arr1, insert them into set
        while(l < n){
            s.insert(arr1[l]);
            l++;
        }
        
        // If there are remaining elements in array arr2, insert them into set
        while(r < m){
            s.insert(arr2[r]);
            r++;
        }
        
        vector<int> ans;
        for(auto it : s){
            ans.push_back(it);
        }
        
        //return vector with correct order of elements
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
