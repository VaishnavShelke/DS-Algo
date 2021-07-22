You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.

Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.

If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
  
  
  
  My Approach:
        1. First declare a a vector that is going to act as a stack, this will save indexs only
        2. Now start traversing the array. push and pop elements in vector stack such that an increasing sequence { only index numbers in vector } is obtained
        3. Traverse this vector and find first point where vector[i] != i;
              This is the start of our unsorted array
        4. Now clear the vector
        
        5. Again traverse the array in reverse order i.e from n-1 to 0
                push and pop elements in the vector such that a decreasin sequence is obtained
        6. Traverse this vector and find first point where vector[i] != n-1-i
              This is the end of our unsorted array
        Now you know both the start and end of the unsorted array
        
  INTBIT Approach:
        1. Travese the array from index 0 to n-1
          Initialize array maxUpto ans assign maxUpto[0] as A[0] as you traverse the array assign max value until now at maxUpto[i]
          
        2. Similarly do it for minUpto[] from the end of the array.
          
        3. Traverse the maxUpto Array from the end and find first point where maxUpto[i] > arr[i], this i is the end of our unsorted array...
        4. Similarly for minUpto
  
