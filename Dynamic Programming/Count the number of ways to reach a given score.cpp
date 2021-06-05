#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                             Count the number of ways to reach a given score                             
 * *                                            Space Optimized                
 * *                 
 **/

int main(){
    int score =0;
    int moves[] = {3,5,10};
    int temp[score+1];

    for(int j = 0; j<4 ; j++){
        for(int i = 0; i<=score ; i++){
            if(j == 0) temp[i] = 0;
            else if(i == 0) temp[i] = 1;
            else if(moves[j-1]>i) temp[i] = temp[i];
            else{
                temp[i] = temp[i] + temp[i-moves[j-1]];
            }

        }
    }

    cout << "Number of ways to reach the given score ... ";
    cout << temp[score];
  
}
