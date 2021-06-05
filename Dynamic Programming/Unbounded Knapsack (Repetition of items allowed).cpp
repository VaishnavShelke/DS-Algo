#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                                 Unbounded KnapSack                                 
 * *                                               
 * *                 
 **/

int main(){
    int W = 8;
    int  val[] = {10, 40, 50, 70};
    int  wt[]  = {1, 3, 4, 5};
    int n = sizeof(val)/sizeof(val[0]);

    int maxVal[W+1];

    for(int j = 0; j<=n ; j++){
        for(int i = 0; i<= W ; i++){
            if(i == 0 || j == 0) maxVal[i] = 0;
            else if(wt[j-1]>i) maxVal[i] = maxVal[i];
            else{
                maxVal[i] = max(maxVal[i],maxVal[i-wt[j-1]] + val[j-1]);
            }
        }
    }
    cout << "The maximum value that can be filled in Knapsack ... " << maxVal[W];
    return 0;
}
