#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;


/*
    Finding common elements in a row wise sorted 3 arrays
    
*/

class Brrays{
public:
    int* arr;
    int sizearr;
    int currentindex = 0;
    //Brrays();
    //Brrays(int* A,int arrsize) {arr = A; sizearr = arrsize;}
    bool inlim(){                                   // Checks wether the array is in bounds or not
        if(currentindex<sizearr){return true;}
        else return false;
    }
};

bool comparer(Brrays a1,Brrays a2){
    return (a1.arr[a1.currentindex]<a2.arr[a2.currentindex]);
}

int main(){
    int arr1[] = {1,4,7,9,12,15,17,18,21,30};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {4,5,17,18,19,22,30};
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[] = {2,4,7,17,18,30};
    int len3 = sizeof(arr3)/sizeof(arr3[0]);
    vector<int> answer;
    Brrays maximumO;
    int maxim;
    Brrays objectarr[3];
    
    objectarr[0].arr = arr1;
    objectarr[0].sizearr = len1;
    objectarr[1].arr = arr2;
    objectarr[1].sizearr = len2;
    objectarr[2].arr = arr3;
    objectarr[2].sizearr = len3;
    
    while(objectarr[0].inlim() && objectarr[1].inlim() && objectarr[2].inlim()){
        maximumO = *max_element(objectarr,objectarr+3,comparer);
        maxim = maximumO.arr[maximumO.currentindex];
        

        for(int i = 0;i<3; i++){
            while(objectarr[i].arr[objectarr[i].currentindex] < maxim){
                if(objectarr[i].inlim())
                        objectarr[i].currentindex++;
                else break;
            }
        }

        if(objectarr[0].arr[objectarr[0].currentindex] == objectarr[1].arr[objectarr[1].currentindex]&&
                objectarr[0].arr[objectarr[0].currentindex] == objectarr[2].arr[objectarr[2].currentindex]){
                    answer.push_back(objectarr[0].arr[objectarr[0].currentindex]);
                    for(int i = 0;i<3;i++){
                        objectarr[i].currentindex++;
                    }
                }
        }
    cout << "The common elements are .....\n";
    for(int i = 0;i<answer.size();i++){
        cout << answer[i] << " ";
    }
    return 0;
}
