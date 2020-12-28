#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


// Buy maximum stocks with the given amount


int main(){
    int stockP[] = { 7, 10, 4 };
    int money = 100;
    int len = sizeof(stockP)/sizeof(stockP[0]);
    vector<pair<int,int>> priceDay;

    for(int i = 0; i < len; i++){
        priceDay.push_back(make_pair(stockP[i],i+1));
    }
    sort(priceDay.begin(),priceDay.end()); //Sort by price by defalut first element
    int i = 0;
    int temp;
    int stocksbought = 0;
    while(i<len){
        if(priceDay[i].first*(i+1) <= money){
            money -= priceDay[i].first*(i+1);
            stocksbought += priceDay[i].second;
        }
        else{
            temp = money/priceDay[i].first;
            stocksbought += temp;
            break;
        }
        i++;
    }
    cout << "The total number {Maximum} Stocks brought are..." << stocksbought;
    return 0;
}
