#include <iostream>
#include<queue>
using namespace std;

// First negative integer in every window of size k

void printFirstNegativeInteger(int* arr,int size,int window){

    // {12, -1, -7, 8, -15, 30, 16, 28}

    queue<int> negatives;
    int index = 0;

    for(index = 0; index<window ; index++){
        if(arr[index]<0){
            negatives.push(index);
        }
    }
    if(negatives.empty()){cout << "0" << " ";}
    else{cout << arr[negatives.front()] << " ";}
    if(!negatives.empty() && 0 == negatives.front()){
        negatives.pop();
    }

    for(index = window ; index < size ; index++){
        if(negatives.empty()){cout << "0" << " ";}
        else{cout << arr[negatives.front()] << " ";}

        if(!negatives.empty() && index-window+1 == negatives.front()){
            negatives.pop();
        }
        if(arr[index]<0){
            negatives.push(index);
        }
    }

}

int main()
{
    int arr[] = {-12, -1, -7, -8, -15, -30, -16, -28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
}
