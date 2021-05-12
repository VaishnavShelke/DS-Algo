#include <iostream>
#include <bits\stdc++.h>

using namespace std;

// Sort the array according to the count of set bits


int countbits(int element){
    int count = 0;

    while(element != 0){
        if(element&1 == 1) count++;
        element = element>>1;
    }
    return count;
}

bool countcompare(int e1, int e2){
    int count1 = countbits(e1);
    int count2 = countbits(e2);

    return count1 > count2; 
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int length = sizeof(arr)/sizeof(arr[0]);

    std::sort(arr,arr+length,countcompare); // Flipping happens when countcompare is true
                                            // So if you want to maintain the
                                            // order of the numbers do not flip
                                            // that is do not return
                                            // a true value from the comparer
    for(int i = 0; i<length ; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
