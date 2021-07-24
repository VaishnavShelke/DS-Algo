Problem Description
Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.
  
Problem Constraints
 1 <= N, B <= 105
 A[i]=0 or A[i]=1

Input Format
First argument is an binary array A.
Second argument is an integer B.

Output Format
Return a single integer denoting the length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.

Example Input
Input 1:
 A = [1, 0, 0, 1, 1, 0, 1]
 B = 1
Input 2:
 A = [1, 0, 0, 1, 0, 1, 0, 1, 0, 1]
 B = 2
Example Output
Output 1:
 4
Output 2:
 5
   
   
   Approach:
        VARIABLE LENGTH SLIDING WINDOW
        initialize left and right
        increment right until count !> B
        as soon as count == B+1 start incrementing left until count != B
        
        And save the lengths of these windows obtained
   
   
   
   
   
   
   
   
   
   
   
   
   
   
