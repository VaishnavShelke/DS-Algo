#include <iostream>
#include <bits\stdc++.h>
using namespace std;

// Find the first circular tour that visits all petrol pumps
 
int printTour(int arr[][2], int n){

    int start; int prevSurplus;
    int currSurplus; int totalSurplus; int index;

    if(arr[0][0] - arr[0][1]>= 0) start = 0;
    else start = -1;

    prevSurplus = arr[0][0] - arr[0][1];

    for(int i = 1; i<2*n ; i++){
        index = i%n;

        if(index == start) return start;
        currSurplus = arr[index][0] - arr[index][1];

        if(currSurplus >= 0 && prevSurplus < 0){
            start = index;
        }
        if(prevSurplus>= 0){
            totalSurplus = currSurplus+prevSurplus;
            if(totalSurplus>=0)
                prevSurplus = totalSurplus;
            else   
                { start = -1;prevSurplus = currSurplus;}}
        else
            prevSurplus = currSurplus;
    }
    return start;
}
