Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]


initialize two variables low = 1; high = sizeofArr;

for(int i = 0 ; i<sizeofArr-1 ; i++){
    if(str[i] == 'I') arr[i] = low++;
    else arr[i] = high--;
}

arr[end] = high;
