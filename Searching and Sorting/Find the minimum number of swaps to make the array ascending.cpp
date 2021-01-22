#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Minimum number of swaps to make the array ascending
/*
    Given: 
            All the numbers in the array are consecutive and distinct
            
*/

int main(){
    int val[] = {1 ,3 ,5 ,2 ,4 ,6 ,7};
                //{4,3,2,1}
    int len = sizeof(val)/sizeof(val[0]);
    int valtoadress[len+1];
    int counter = 0;

    for(int i = 0;i<len;i++){
        valtoadress[val[i]] = i; 
    }
    int ad1,ad2,temp;
    for(int i = 0;i<len; i++){
        if(val[i] != i+1){
            if(i+1 == val[val[i]-1]){
                counter++;
                ad1 = i;
                temp = val[i];
                ad2 = valtoadress[i+1];
                swap(val[ad1],val[ad2]);
                valtoadress[temp] = temp-1;
                valtoadress[i+1] = i;
            }
            else{
                counter++;
                ad1 = i;
                temp  = val[i];
                ad2 = valtoadress[i+1];
                swap(val[ad1],val[ad2]);
                valtoadress[i+1] = i;
                valtoadress[temp] = ad2;
            }
        }
        
    }
    cout << counter;
    
}
