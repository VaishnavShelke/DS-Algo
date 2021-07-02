#include<iostream>
#include<unordered_map>
#define INF 99999
using namespace std;

/*
int maxMinusMin(int* price,int inclTop){
    int maxProfit = 0;
    int maxPrice =  price[inclTop];
    for(int j = inclTop; j>=0 ; j++){
        if(maxProfit<maxPrice-price[j]){
            maxProfit = maxPrice-price[j];
        }   
        maxPrice = max(maxPrice,price[inclTop]);       
    }
    return maxProfit;
}
*/

class Solution {
  public:

    int maxProfit(int K, int N, int A[]) {
        unordered_map<int,unordered_map<int,int>> memo;
        return maxProfitUntil(A, N-1, K,memo);
    }

int maxProfitUntil(int* price,int inclTop,int k,unordered_map<int,unordered_map<int,int>>& memo){

    if(memo.find(inclTop) != memo.end()){
        if(memo[inclTop].find(k) != memo[inclTop].end()){
            return memo[inclTop][k];
        }
    }

    if(k == 0){
        return 0;
    }
    if(inclTop == 1){
        return max(0,price[1]-price[0]);
    }
    int maxProfit = 0;
    int maxPrice = price[inclTop];
    int maxNet = 0;

    for(int j = inclTop-1; j>= 0 ; j--){
        if(maxProfit<maxPrice-price[j]){
            maxProfit = maxPrice-price[j];
            maxNet = max(maxNet,maxProfit + maxProfitUntil(price,j-1,k-1,memo));
        }   
        maxPrice = max(maxPrice,price[j]);
        
    }
    memo[inclTop][k] = maxNet;
    return maxNet;

}
