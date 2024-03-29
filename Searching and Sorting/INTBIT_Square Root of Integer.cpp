Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY




Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))
Constraints

1 <= A <= 10^9
For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3
      
Someones Approach:
  take appropriate start = 1 and end = X
   then mid = start + (end-start)/2;
   
   if(mid > X/mid){
     end = mid - 1;
   }
   else{
     start = mid + 1;
     answer = start;
   }
      
      
      
      
      
      
      
      
      
      
      
      
      
