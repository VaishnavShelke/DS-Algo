Remove Element

Given an array and a value, remove all the instances of that value in the array. 

Also return the number of elements left in the array after the operation.

It does not matter what is left beyond the expected length.

Example:

If array A is [4, 1, 1, 2, 1, 3]

and value elem is 1, 

then new length is 3, and A is now [4, 2, 3]

Try to do it in less than linear additional space complexity.
  
  
My Approach:
  Initialize hunter = 0; and dog = 0;

  while(dog < n){
      if(arr[hunter] != k) hunter++;
      else{
          dog = max(hunter+1,dog);
          while(dog<n && arr[dog] != k) dog++;
          if(dog < n ){ swap(arr[dog],arr[hunter]);
          hunter++;}
      }
  }
   answer is hunter + 1;
  
