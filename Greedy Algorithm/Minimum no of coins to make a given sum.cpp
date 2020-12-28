#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


// Find the minumum number of coins required to reach a given sum;
/*
At any point of time you have 2 situations....
    1. The last element {coin denomination} is >>> value required
            In that case the only choice that you have is to deduct the coin from you avalaibility space
            ava -->> ava-1
            val -->> val
    2. The last element is less than the val to be made
            In that case you can take 1 piece or 2,3,4 or even 0 instances of that denomination
            whichever of these choices give you least number of coins is your answer
            min of {
                from number of coins 0 -->> floor(val/coins[ava-1].....
                ava -->> ava-1
                val -->> val - coins[ava-1]*(number of coins used)
                temp = minimum of -->> minRC[ava-1][val - coins[ava-1]*(number of coins used)] + number of coins used <<-OR->> temp -->>
            }
*/
int main(){
    int avacoins[] = {25, 10, 5};
    //sort(avacoins,avacoins + 4);
    int value = 30;
    int minima;
    int t_coinsava = sizeof(avacoins)/sizeof(avacoins[0]);
    int minCR[t_coinsava+1][value+1];
    int counts;
    for(int ava = 0;ava <= t_coinsava;ava++){
        for(int val = 0; val <= value; val++){
            if(val == 0){ minCR[ava][val] = 0;continue;}
            if(ava == 0){ minCR[ava][val] = 1e6;continue;}

            if(val < avacoins[ava-1]) minCR[ava][val] = minCR[ava-1][val];
            else{
                counts = floor(val/avacoins[ava-1]);
                //cout << counts <<"\n";
                minima = 1e6;
                for(int i = 0; i<= counts; i++){
                    minima = min(minima,minCR[ava-1][val-i*avacoins[ava-1]]+i);
                }
                minCR[ava][val] = minima;
                }
        }
    }

    cout <<minCR[t_coinsava][value];
    return 0;
}
