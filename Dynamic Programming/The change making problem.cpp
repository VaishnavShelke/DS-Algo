#include <iostream>
#include <vector>
using namespace std;

/* There are two ways of getting the desired amount
   1. Either you use one{last in array coin} -> subproblem with reduced amount but same number of coins
   2. Or you do not use the coin at all -> subproblem with reduced choice of coins but the same amount to be made
*/


int main(){
    int t_amount = 4; // Amount that is to be made
    int t_coins = 3;  // Number of types of coins + 1
    int s[t_coins] = {1,2,3};
    int ways[t_coins+1][t_amount+1];

    for (int coins = 0; coins <= t_coins ; coins++){
        for (int amount = 0; amount <= t_amount; amount++){
            if (amount == 0) {ways[coins][amount] = 1; continue;}
            if (coins == 0) {ways[coins][amount] = 0;continue;}

            if (amount-s[coins-1]>=0) ways[coins][amount] = ways[coins-1][amount] + ways[coins][amount-s[coins-1]];
            else ways[coins][amount] = ways[coins-1][amount];
        }
    }
    cout << ways[2][1] << "\n";
    cout << "Number of ways to make change for " << t_amount <<" is "<< ways[t_coins][t_amount];
    return 0;


}
