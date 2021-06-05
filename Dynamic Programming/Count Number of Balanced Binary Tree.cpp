#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                             Calculate the number of balanced trees possible with given height h                            
 * *                   count[h] = sum { count[h-1]*count[h-1] , count[h-1]*count[h-2], count[h-2]*count[h-1] }
 **/

int main(){
    int height = 10;
    int first = 1;
    int temp;
    int second = 1;

    for(int h = 2; h<=height ; h++){
        temp = first*first + first*second + second*first;
        second = first;
        first = temp;
    }
    cout << "The possible number of balanced binary trees with the given height .... " << first;
    return 0;

}
