#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
//  Fin d specific pair in the matrix
/*
    The objective is to find the maximum value of mat(c,d) - mat(a,b)
    subject to condition that c > a and d > b or a < c and b < d

    Clue ... 
    Our approach is to keep the track of minimum number in a rectangel form (0,0) to (j,i) we are sitting at
    and storing the value at index (j,i);
    to get the minimum out of { (j,i-1) / (j-1,i) / (j-1,i-1)} rectangles {three rectanngles ending at given coordinates}

    But before doing this all...
        Suppose we are at the index (i,j) first store the value of mat(i,j) - mat(i-1,j-1) if it is greater than the maximum til now
*/
int main(){
    int matrix[][5] =  {{ 1, 2, -1, -4, -20 },
                        { -20, -3, 4, 2, 1 }, 
                        { 3, 8, 6, 1, 3 },
                        { -4, -1, 1, 77, -6 },
                        { 0, -4, 10, -5, 1 }};
    int maxima = INT_MIN;

    for(int j  = 0; j<5 ;j++){
        for(int i = 0; i<5 ;i++){
            if(i == 0 && j== 0) continue;
            if(j == 0){matrix[j][i] = min(matrix[j][i-1],matrix[j][i]); continue;}
            if(i == 0){matrix[j][i] = min(matrix[j-1][i],matrix[j][i]); continue;}

            maxima = max(maxima,matrix[j][i] - matrix[j-1][i-1]);

            // Finding and assigining minima among FOUR
            matrix[j][i] = min(matrix[j-1][i],matrix[j][i]);
            matrix[j][i] = min(matrix[j-1][i-1],matrix[j][i]);
            matrix[j][i] = min(matrix[j][i-1],matrix[j][i]);
        }
    }
    cout << "The pair which you want has a difference of ... " << maxima;
    
}
