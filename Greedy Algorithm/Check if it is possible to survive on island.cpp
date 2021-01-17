#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
// Check if it is possible to survive on an island

int main(){

    int days_to_survive = 10;
    int daily_consumption = 2;
    int max_buy = 16;
    int total_buys = 0;
    
    int total_stock_req = days_to_survive*daily_consumption;
    int big_billion_days = days_to_survive%7 + (days_to_survive/7)*6;
    int total_buying_cap = big_billion_days*max_buy;
    if(total_stock_req > total_buying_cap){
        cout << "You have chosen death ... ";
    }
    else{
        total_buys = ceil(total_stock_req*1.0/max_buy);
        cout << "You survive if you buy " << total_buys << " times";
    }
    return 0;
}
