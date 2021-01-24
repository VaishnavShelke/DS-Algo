#include <iostream>
#include <bits\stdc++.h>

using namespace std;



// Maximum sum increasing sub sequence

int main(){
    int arr[] = {1, 10, 12,45,6,5,768,786,6,5,543,2,31, 2, 3, 100, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);

    int maxsumincreasinguptome[len];
    maxsumincreasinguptome[0] = arr[0];

    for(int i = 1; i<len ; i++){
        maxsumincreasinguptome[i] = arr[i];
        for(int j = 0; j<i ; j++){
                if(arr[i] > arr[j]){
                    maxsumincreasinguptome[i] = max(maxsumincreasinguptome[i],maxsumincreasinguptome[j]+arr[i]);
                }
        }
    }

    cout << "The maximum sum increasing sub sequence is ... " << *max_element(maxsumincreasinguptome,maxsumincreasinguptome+len);
    return 0;

}
