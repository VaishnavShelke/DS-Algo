#include <iostream>
// Maximum dimension square

/*
    Let K[j][i] represent the side length of the maximum dimension square whose ( j, i) is
    the bottom-right most coordinate.

    now suppose we are at the unexplored coordinate whose value at the point is 1.
    Then the K[j][i] value for this coordinate is going to be
    the minimum of k[j][i-1] / k[j-1][i] / k[j-1][i-1] plus 1
    Please try to visualize the above 3 lines carefullly then youo will understand what the PLUS 1 is doing
    and why we go for the MINIMUM 
*/

int main(){
    int height = 6;
    int width = 5;
    int square[height][width]        = {{0, 1, 1, 0, 1},  
                                        {1, 1, 0, 1, 0},  
                                        {0, 1, 1, 1, 0},  
                                        {1, 1, 1, 1, 0},  
                                        {1, 1, 1, 1, 1},  
                                        {0, 0, 0, 0, 0}}; 
    int sqaredim[height][width];
    int maxima = 0;
    for(int j = 0; j<height ; j++){
        for(int i = 0; i<width ; i++){

            if(j == 0) {sqaredim[j][i] = square[j][i]; continue;}
            if(i == 0) {sqaredim[j][i] = square[j][i]; continue;}
            if(square[j][i] == 1){
                sqaredim[j][i] = min(sqaredim[j-1][i],sqaredim[j][i-1]);
                sqaredim[j][i] = min(sqaredim[j][i],sqaredim[j-1][i-1])+1;
            }
            else{
                sqaredim[j][i] = 0;
            }
            maxima = max(maxima,sqaredim[j][i]);
        }
    }
    cout << "The maximum dimension square is ... " << maxima;
    return 0;
}
