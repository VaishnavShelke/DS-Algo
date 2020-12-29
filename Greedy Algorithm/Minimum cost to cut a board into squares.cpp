#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// Minimum cost to cut a board into squares

// The most expensive cut out of vertical and horizontal combined is the first one to be implemented


bool comparer(int c1,int c2);

int main(){
    int verticalcost[] = {4, 1, 2};
    int vertlen = sizeof(verticalcost)/sizeof(verticalcost[0]);
    int horizontalcost[] = {2, 1, 3, 1, 4};
    int horlen = sizeof(horizontalcost)/sizeof(horizontalcost[0]);
    sort(verticalcost,verticalcost+vertlen,comparer);
    sort(horizontalcost,horizontalcost+horlen,comparer);

    int remcuts = vertlen + horlen;
    int x_cuts = 1;
    int y_cuts = 1;
    int horptr = 0,verptr = 0;
    int t_cost = 0;
    while(true){
        if(horptr == horlen){
            while(verptr < vertlen){
                t_cost += verticalcost[verptr]*x_cuts;
                verptr++;
            }
            break;
        }
        else if(verptr == vertlen){
            while(horptr < horlen){
                t_cost += horizontalcost[horptr]*y_cuts;
                horptr++;
            }
            break;
        }
        else{
            if(horizontalcost[horptr]>verticalcost[verptr]){
                t_cost += horizontalcost[horptr]*y_cuts;
                horptr++;
                x_cuts++;
            }
            else{
                t_cost += verticalcost[verptr]*x_cuts;
                verptr++;
                y_cuts++;
            }
        }
    }
    cout << "Total minimum cutting cost....." << "  "<< t_cost;
    return 0;
}

bool comparer(int c1,int c2){
    return (c1 > c2);
}
