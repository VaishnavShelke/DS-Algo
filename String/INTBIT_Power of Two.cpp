Find if Given number is power of 2 or not. 

More specifically, find if given number can be expressed as 2^k where k >= 1.

Input:

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)
Output:

return 1 if the number is a power of 2 else return 0

Example:

Input : 128
Output : 1
  
  
My Approach { Inferior to INTBIT }:
      
      take chunk of length 8 from the beginning convert it to int
      divide the int by 2 and store the quotient as a string { to be appended to quotient from next chunk }
      find remainder and append it everytime to front of next chunk.
        
      This step is division by 2.....
        
      Do it until
      The final answer is either 1 or the number is not divisible by 2
        
INTBIT:
    Use recursion for cleaner code.........
