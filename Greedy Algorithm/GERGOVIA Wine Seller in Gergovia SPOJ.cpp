//C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;

// GERGOVIA Wine Seller in Gergovia SPOJ


int wineSeller(int* arr,int towns){
    int j;
    int work = 0;
    for(int i = 0; i<towns-1 ; i++){
        if(arr[i] != 0){
            if(arr[i]>0){   // I is a seller
                j = i + 1;
                while(arr[i] != 0){
                    if(arr[j]<0){
                        if(arr[i] + arr[j] >= 0){
                            work += std::abs(arr[j]*(j-i));
                            arr[i] = arr[i] + arr[j];
                            arr[j] = 0;
                        }
                        else{
                            work += std::abs(arr[i]*(j-i));
                            arr[j] = arr[j] + arr[i];
                            arr[i] = 0; 
                        }
                    }
                    j++;
                }
            }
            else{           // I is a buyer
                j = i + 1;
                while(arr[i] != 0){
                    if(arr[j]>0){
                        if(arr[i] + arr[j] > 0){
                            work += std::abs(arr[i]*(j-i));
                            arr[j] = arr[j] + arr[i];
                            arr[i] = 0;
                        }
                        else{
                            work += std::abs(arr[j]*(j-i));
                            arr[i] = arr[i] + arr[j];
                            arr[j] = 0;
                        }
                    }
                    j++;
                }

            }
        } 
    }
    return work;
}

int main(){
/*
    int towns = 6;
    int arr[] = { -1000, -1000, -1000, 1000, 1000, 1000};
    cout << wineSeller(arr,towns);
*/
    int testcases;
    int towns;
    int * arr;
    cin>>testcases;
    for(int j = 0; j<testcases ; j++){ 
        cin>> towns;
        arr = new int[towns];
        for(int i = 0; i<towns; i++){
            cin>>arr[i];
        }
        cout << wineSeller(arr,towns);
        delete [] arr;
    }
    return 0;
}
