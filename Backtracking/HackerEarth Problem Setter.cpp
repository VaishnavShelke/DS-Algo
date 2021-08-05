/*
Minimize absolute difference.

you can divide even number by 2
you can multiply odd number by 2
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 99999


int finMinDif(map<int,int>& dic){

    int low = dic.begin()->first;
    int high = dic.rbegin()->first;
    int diff  =  INF;

    while(1){
        low = dic.begin()->first;
        high = dic.rbegin()->first;        
        if(high - low >= diff) break;
        else diff = high-low;
        if((low + high) % 2 == 0){
            if(high%2 == 0){
                dic.erase(high) ; high = high/2; dic[high] = 1;
            }
            else{
                dic.erase(low); low = low*2; dic[low] = 1;
            }
        }
        else{
            if(high%2 == 0){
                int duph = high;
                int dupl = low;
                dic.erase(high); high = high/2 ; dic[high] = 1;
                diff = min(diff,finMinDif(dic));
                dic.erase(high); dic[duph] = 1;

                dic.erase(low); low = low*2; dic[low] = 1;
                diff = min(diff,finMinDif(dic));
                dic.erase(low); dic[dupl] = 1;


                dic.erase(high); high = high/2 ; dic[high] = 1;
                dic.erase(low); low = low*2; dic[low] = 1;
                diff = min(diff,finMinDif(dic));
                return diff;
            }
            else{
                break;
            }
        }
        
    }
    return diff;
}

int main(){
    vector<int> A = {2 , 4 , 8 , 16};
    map<int,int> dic;
    for(int i = 0; i<A.size() ; i++) dic[A[i]] = 1;
    cout <<  finMinDif(dic);
}
