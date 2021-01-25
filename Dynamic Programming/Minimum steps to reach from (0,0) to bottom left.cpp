#include <iostream>
// Minimum number of steps to reach upto me;
/*
    Consider 0 steps possible station also as this is a death trap
*/

int main(){
    int arr[] = {1, 0,5,6,2,25,4,1, 1, 1, 1, 1, 1, 1};
    int len = sizeof(arr)/sizeof(arr[0]);

    int stepsupotme[len];
    stepsupotme[0] = 0;

    cout << "Minimum Steps to reach the end ... ";
    for(int i = 1; i<len ; i++){
        stepsupotme[i] = 10e6;
        for(int j = 0; j<i ; j++){
            if(i-j <= arr[j]){
                stepsupotme[i] = min(stepsupotme[i],stepsupotme[j]+1);
            }
        }
        cout << stepsupotme[i] << " ";
    }
    return 0;
}
