Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]


My Approach:
  Dynamic allocation of triangular matrix
  
  int** triangle = new int*[N]  // N is the height of the Triangle
  for(int i = 0; i<N ; i++)
            triangle[i] = new int[i+1];

  ......
  ......
  ......
   
  for(int i = 0; i<N ; i++)
              delete []triangle[i];

  delete []triangle;
              
