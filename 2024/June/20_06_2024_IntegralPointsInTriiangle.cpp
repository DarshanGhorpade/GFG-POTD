/*
Given three non-collinear points whose co-ordinates are p(p1, p2), q(q1, q2) and r(r1, r2) in the X-Y plane. Return the number of integral / lattice points strictly inside the triangle formed by these points.
Note: - A point in the X-Y plane is said to be an integral / lattice point if both its coordinates are integral.

Examples

Input: p = (0,0), q = (0,5), r = (5,0)
Output: 6
Explanation: 

As shown in figure, points (1,1) (1,2) (1,3) (2,1) (2,2) and (3,1) are the integral points inside the triangle. So total 6 are there.
Input: p = (62,-3), q = (5,-45), r = (-19,-23)
Output: 1129
Explanation: There are 1129 integral points in the triangle formed by p, q and r.
Expected Time Complexity: O(Log2109)
Expected Auxillary Space: O(1)

Constraints:
-109 ≤ x-coordinate, y-coordinate ≤ 109
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int gcd(long long int a, long long int b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        long long int p1 = p[0], p2 = p[1];
        long long int q1 = q[0], q2 = q[1];
        long long int r1 = r[0], r2 = r[1];

        // Calculate the area using the determinant method
        long long int area = abs(p1 * (q2 - r2) + q1 * (r2 - p2) + r1 * (p2 - q2));

        // Calculate boundary points using gcd
        long long int boundaryPoints = gcd(abs(q1 - p1), abs(q2 - p2)) +
                                       gcd(abs(r1 - q1), abs(r2 - q2)) +
                                       gcd(abs(p1 - r1), abs(p2 - r2));

        // Apply Pick's theorem to find the number of integral points inside the triangle
        long long int interiorPoints = (area - boundaryPoints + 2) / 2;
        return interiorPoints;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends
