#include <bits/stdc++.h>
using namespace std;

// Maximum profit by buying and selling a share at most twice

int maxProfit(int* price,int n){


    int maxProfitBase[n];
    int maxP = 0;
    int highest = price[n-1]; maxProfitBase[n-1] = 0;
    for(int i = n-2; i>=0 ; i--){
        if(highest-price[i]>maxP){
            maxP = highest-price[i];
            maxProfitBase[i] = maxP;
        }
        else{
            maxProfitBase[i] = maxProfitBase[i+1];
        }
        highest = max(highest,price[i]);
    }


    int maxProfitTop[n];
    maxP = 0;
    int lowest = price[0]; maxProfitTop[0] = 0;

    for(int i = 1; i<n ; i++){
        if(price[i]-lowest>maxP){
            maxP = price[i]-lowest;
            maxProfitTop[i] = maxP;
        }
        else{
            maxProfitTop[i] = maxProfitTop[i-1];
        }
        lowest = min(lowest,price[i]);
    }

    for(int i = 0; i<n ; i++){
        maxP = max(maxP,maxProfitBase[i]+maxProfitTop[i]);
    }
    return maxP;

}



int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n);
    return 0;
}
