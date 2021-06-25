#include <iostream>
using namespace std;

// SubSet Sum

void subsetSums(int* arr,int N){

    int subSum;
    for(int counter = 0; counter < 1<<N ; counter++){
        subSum = 0;

        for(int j = 0; j<N ; j++){
            if(1<<j & counter){
                subSum += arr[j];
            }
        }

        cout << subSum << " ";
    }
    return;
}

int main()
{
    int arr[] = { 5, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    subsetSums(arr,n);
    return 0;
}
