Problem Description

There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.
Find the minimum total cost to paint all houses.

Problem Constraints
1 <= N <= 105
1 <= A[i][j] <= 103

Input Format
First and only argument is an 2D integer matrix A of size N x 3 denoting the cost to paint the houses.

Output Format
Return an integer denoting the minimum total cost to paint all houses.

Example Input
Input 1:

 A = [  [1, 2, 3]
        [10, 11, 12]
     ]

// Approach.

dp[1][i] = A[1][i] + min(dp[0][i-1],dp[2][i-1])
dp[2][i] = A[2][i] + min(dp[0][i-1],dp[1][i-1])
dp[0][i] = A[0][i] + min(dp[1][i-1],dp[2][i-1])

return minimum of the three dp[1][n] - dp[0][n] - dp[2][n]


