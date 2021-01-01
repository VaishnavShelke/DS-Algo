#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// Buy and sell stocks to maximize profits

/* Look for the ramps,
    When the ramp begins to go up buy, and when the cliff edge is reached sell
*/

int main(){
    int stockprices[] = { 100, 100,160,160 };
    int len = sizeof(stockprices)/sizeof(stockprices[0]);
    int start,ends;
    int i = 0;
    int j;
    while(i < len){
        start = i;
        for( j = i; j< len-1;j++){
            if(stockprices[j+1]<stockprices[j])
            {   ends = j;
                break;}
            else{
                ends = j+1;
            }
        }

        if (i<j){
            cout << "Buy At...  " << i << "  Sell At...  "<< j<<"\n";
            cout << "Profit Booked .... " << stockprices[j] - stockprices[i] << "\n";
        }
        i = j + 1;
    }

}
