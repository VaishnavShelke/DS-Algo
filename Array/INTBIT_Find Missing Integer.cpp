Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
  
My Aprroach:
      Couldn't solve

INTBIT Approach:
      Traverse the array...
        1. If any number lies in range 1 .... N let us say that number is A 
        2. Send that A to index A-1
        
        3. Finally again traverse the array if Arr[i] != i + 1 then i + 1 is our answer...
    
How to send the A to index A-1
       for( int i = 0; i < arrsize ; i++){
          if(arr[i] in range (1,N){
              swap(arr[i],arr[N-1]);
              i--;
          } 
       }
