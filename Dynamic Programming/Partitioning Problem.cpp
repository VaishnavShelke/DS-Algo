#include <iostream>
#include <bits\stdc++.h>
using namespace std;


/**
 * !                             Partition problem                                
 * *                                               
 * *                 
 **/

int main(){
    int arr[] = { 3, 1, 5, 9, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for(int i = 0; i<n ; i++){
        sum += arr[i];
    }
    if(sum%2 == 1) {cout << "No Partitioning Possible ... "; return 0;}
    else sum = sum/2;

    bool arr1[sum+1],arr2[sum+1];
    bool *makeWithNow = arr1;
    bool *makeWithBack = arr2;
    bool* temp;

    for(int j = 0; j<=n ; j++){
        for(int i = 0; i<=sum ; i++){
            if(i == 0) makeWithNow[i] = true;
            else if(j == 0) makeWithNow[i] = false;
            else if(arr[j-1] > i) makeWithNow[i] = makeWithBack[i];
            else
                makeWithNow[i] = makeWithBack[i] || makeWithBack[i-arr[j-1]];
        }
        for( int k = 0; k<=sum ; k++) cout << makeWithNow[k] << " ";
        cout << "\n";
        temp = makeWithNow;
        makeWithNow = makeWithBack;
        makeWithBack = temp;

    }
    if(makeWithBack[sum]){
        cout << "Partitionning Possible ... ";
    }
    else{
        cout << "Partitioning Impossible ... ";
    }
    return 0;
}
