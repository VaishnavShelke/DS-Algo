//C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;

int bearGrillsUtil(int awf,pair<int,int> H_A,unordered_map<int,unordered_map<int,unordered_map<int,int>>>& memo){

    if(memo.find(awf) != memo.end()){
        if(memo[awf].find(H_A.first) != memo[awf].end()){
            if(memo[awf][H_A.first].find(H_A.second) != memo[awf][H_A.first].end()){
                return memo[awf][H_A.first][H_A.second];
            }
        }
    }
    if(H_A.first <= 0 || H_A.second <= 0) return 0;
    if(awf == 1){
        memo[awf][H_A.first][H_A.second] = max(bearGrillsUtil(0,{H_A.first+3,H_A.second+2},memo),bearGrillsUtil(2,{H_A.first-20,H_A.second+5},memo)) + 1;
        return memo[awf][H_A.first][H_A.second];
    }
    else if(awf == 2){
        memo[awf][H_A.first][H_A.second] = max(bearGrillsUtil(1,{H_A.first-5,H_A.second-10},memo),bearGrillsUtil(0,{H_A.first+3,H_A.second+2},memo)) + 1;
        return memo[awf][H_A.first][H_A.second];
    }
    else{
        memo[awf][H_A.first][H_A.second] = max(bearGrillsUtil(1,{H_A.first-5,H_A.second-10},memo),bearGrillsUtil(2,{H_A.first-20,H_A.second+5},memo)) + 1; 
        return  memo[awf][H_A.first][H_A.second];
    }
}

int bearGrills(int initialH,int initialA){

    pair<int,int> H_A{initialH,initialA};

    unordered_map<int,unordered_map<int,unordered_map<int,int>>> memo;
    int result = max(bearGrillsUtil(1,{H_A.first-5,H_A.second-10},memo),bearGrillsUtil(2,{H_A.first-20,H_A.second+5},memo));
    return max(result,bearGrillsUtil(0,{H_A.first+3,H_A.second+2},memo));

}


int main(){

    int testcases;
    int initialH,initialA;
    cin>>testcases;

    for(int i = 0; i<testcases ; i++){
        cin>>initialH>>initialA;
        cout << bearGrills(initialH,initialA);
    }
}
