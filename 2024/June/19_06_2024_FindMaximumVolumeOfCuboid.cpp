/*
You are given a perimeter & the area. Your task is to return the maximum volume that can be made in the form of a cuboid from the given perimeter and surface area.
Note: Round off to 2 decimal places and for the given parameters, it is guaranteed that an answer always exists.

Examples

Input: perimeter = 22, area = 15
Output: 3.02
Explanation: The maximum attainable volume of the cuboid is 3.02
Input: perimeter = 20, area = 5
Output: 0.33
Explanation: The maximum attainable volume of the cuboid is 0.33
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints :
1 ≤ perimeter ≤ 109
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
        double h=(perimeter-sqrt(perimeter*perimeter-24*area))/12;
        double l=(perimeter/4-2*h);
        return h*h*l;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends

/*

Detailed Explanation and working code:
We are given the perimeter and area of the cuboid and we have to get the maximum value of the volume of the cuboid and we have to round it off to 2 decimal places.

we know that :-

perimeter (P) of cuboid = 4 * ( l + w + h )

surface area (A) of cuboid = 2 * ( l * w + w * h + h * l)

volume (V) of cuboid = l * w * h 

where

l = length of cuboid

w = width of cuboid

h = height of cuboid 

we don't have the values of  the parameter l , w and h only we have the values of perimeter and surface area

so we have to use the given data to find the values of the parameters  l , w and h 

then we can find the value of the maximum volume 

to get maximum value of the volume  of cuboid :-

let us first determine the value of the parameter h :-

now to determine value of the parameter h reprsenting the volume of cuboid in terms of h 

 

perimeter (P) of cuboid = 4 * ( l + w + h )

surface area (A) of cuboid = 2 * ( l * w + w * h + h * l)

volume (V) of cuboid = l * w * h 

                                   = ( l * w ) * h             say equation ( i )

let us determine the value of l * w :

using the surface area (A) of cuboid:

surface area (A) of cuboid = 2 * ( l * w + w * h + h * l)

arranging the above equation:

l * w = A/2 - ( w * h + h * l )

arranging above equation:

l * w = A/2 - ( h * ( w + l ) )                         say equation (ii)

let us determine the value of  w + l  :

using the perimeter (P) of cuboid:

perimeter (P) of cuboid = 4 * ( l + w + h )

arranging the above equation:

P/4 = l + w + h

arranging the above equation:

w + l = P/4 - h

now substituting the value of w + l  in  equation (ii):

l * w = A/2 - ( h * ( w + l ) ) 

l * w = A/2 - ( h * ( P/4 - h ) )    

now substituting the value of  l * w  in  equation (i):

volume (V) of cuboid = ( l * w ) * h

volume (V) of cuboid = ( A/2 - ( h * ( P/4 - h ) ) ) * h

rearranging the above equation:

V =  A/2 * h - h * h * P/4 + h * h * h                               say equation(iii)

as we have to maximize V we can use the concept of minima and maxima (application of derivative)  as V is function of h means value of V is changing with h:

Maxima and minima are the largest and smallest value of the function respectively either within a given range or on the entire domain. Collectively they are also known as extrema of the function. The maxima and minima are the respective plurals of maximum and minimum of a function. 

Maxima and minima are found by using the concept of derivatives . As we know the concept of derivatives gives us the information regarding the gradient or slope of the function, we locate the points where the gradient is zero and these points are called turning points or stationary points. These are points associated with the largest or smallest values (locally) of the function.

As we have to find the maximum value of V we have to find maxima : 

where maxima is the value of h associated with the maximum value of volume:

How to Find Maxima of function f(x) ?
To find the maxima of a function, we need to find a derivative of a function f(x) and find the critical numbers . Then, find the second derivative of a function f(x) and put the critical numbers. If the value is negative, the function has relative maxima at that point, if the value is positive, the function has relative minima at that point.

now let us differentiate the equation (iii)  with respect to h to get maxima of V:

V = f(h)

dV/dh = A/2 - 2 * h * P/4 + 3 * h * h          say equation(iv)

now for critical points  dV/dh = 0

so

A/2 - 2 * h * P/4 + 3 * h * h = 0

A - h *  P + 6 * h * h = 0

using the quadractic formula  :-

h = (  P ± √( P * P - 4 * 6 * A) ) / (2 * 6)

from above expression we have two critical points let h1 and h2:

h1= (  P + √( P * P - 4 * 6 * A) ) / (2 * 6)

and h2 = (  P - √( P * P - 4 * 6 * A) ) / (2 * 6)

now to find which one is maxima we will  find the second derivative of a function V  and put the h1 and h2 ( h1 and h2 are critical points ). If the value is negative, the function has relative maxima at that point

so now differentiating equation(iv) with respect to h:

d/dh(dv/dh)=d2 V/dh2

                   = 0 - 2 *  P/4 + 6 * h

                   = 6 * h - P/2                  say eqaution (v)

now put h1 and h2 at place of h in equation (v) to check which one is maxima point 

for h1 :

put h1 in eqaution (v):

d2 V/dh2 = 6 * h - P/2 

                = 6 * h1 - P/2

                = 6 * ( P + √( P * P - 4 * 6 * A) ) / (2 * 6) - P/2

                = (√( P * P - 4 * 6 * A) ) / (2)              say equation(a)

from the above equation(a) we can see d2 V/dh2

will be positive  

so we can conclude that at h1 there is no maxima

now  for h2 :

put h2 in eqaution (v):

d2 V/dh2 = 6 * h - P/2 

                = 6 * h2 - P/2

                = 6 * ( P - √( P * P - 4 * 6 * A) ) / (2 * 6) - P/2

                = - √( P * P - 4 * 6 * A)  / 2             say equation(b)

from the above equation(b) we can see d2 V/dh2

will be negative  

so we can conclude that at h2 there is  maxima 

thus at h = h2 we will have maximum value of volume of cuboid 

we got value of h = (  P - √( P * P - 4 * 6 * A) ) / (2 * 6) at which we have maximum volume

now for other two remaining parameters that are l and w :

let us find value of w :

 P = 4 * (h + w + l)

l = P/4 - (h + w )

as we have V = l * h * w

V = l * h * w

 V=  ( P/4 - (w + h )) * h * w

V = h * w * P/4 - w * w * h - h * h *w            say equation(vi)

now for maximum value of V 

again we can use the concept of minima and maxima

following the same procedure which we followed 

differentiate equation(vi) with respect to h:

dV/dh= w * P/4 - w * w  - 2 * h * w    say equation(c)

differentiate equation(vi) with respect to w:

dV/dw= h * P/4 - 2 * h * w- h * h say eqution(d)

comparing the equation c and d we can say that both the equation has same coefficient 

so if we put h=w in equation(c) we'll get eqution(d) or we put w=h in equation(d) we'll get eqution(c) 

thus from the above observation we can say both will give the same critical points 

thus we can conclude that w should equal to h to maximize the volume

so w=h

now 

l = P/4 - (h + w )                  say equation(vii)

as w should equal to h 

using this equation(vii) reduces to 

l = P/4 -(2* h)

thus we have determined value of all parameters to find maximum volume

h = (  P - √( P * P - 4 * 6 * A) ) / (2 * 6)

w = h

l = P/4 -( 2 * h )

maximum volume will be l*w*h= l * h * h

*/
