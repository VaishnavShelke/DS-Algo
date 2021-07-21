Problem Description

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).
   
   
   My Approach:
        Initialize a vector of pairs...
          Store {A[i] , i}
        1. Sort the vector by first value
        2. In sorted vector traverse the array from j == len-1 to 0 initialize max index == A[j].second
        3. At each point update max index and find the difference between A[i].second and max Index this is pur possible answer
        4. return the maximum of all the answers








