#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

// Maximum Possible profit with atmost two transactions

int main(){
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);

    int profit_i_end[n]; //incl both
    int profit_0_i[n];   //incle both

    for(int i = 0; i<n ; i++){
        profit_0_i[i] = 0;
        profit_i_end[i] = 0;
    }

    int max_price = price[n-1]; //incl both

    for(int i = n - 2; i>=0 ; i--){
        max_price = max(max_price,price[i]);
        profit_i_end[i] = max(max_price - price[i],profit_i_end[i]);
    }

    int min_price = price[0];

    for(int i = 1; i < n; i++){
        min_price = min(min_price,price[i]);
        profit_0_i[i] = max(price[i] - min_price,profit_0_i[i-1]);
    }

    int max_overall = INT_MIN;

    for(int i = 0; i<n ; i++){
        max_overall = max(max_overall, profit_0_i[i] + profit_i_end[i]);
    }

    cout << max_overall << " Is the maximum profit";
    return 0;

}
