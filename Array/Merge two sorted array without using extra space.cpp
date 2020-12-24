#include <iostream>
#include <typeinfo>
using namespace std;

// Merge two sorted array without using extra space
void swap_and_set(int brr[],int sizearr);

int main(){
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};
    int len1 = sizeof(arr1)/sizeof(arr1[0]);
    int len2 = sizeof(arr2)/sizeof(arr2[0]);
    int upto = min(len1,len2);
    int st1 = 0,st2 = 0;
    while(st1 < len1){
        if (arr1[st1] > arr2[st2]){
            swap(arr1[st1],arr2[st2]);
            swap_and_set(arr2,len2);
        }
        st1++;
    }
    for(int i = 0; i < len1; i++){
        cout << arr1[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < len2; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}

void swap_and_set(int brr[],int sizearr){
    int i = 0;
    while(i < sizearr - 1){
        if(brr[i+1]<brr[i]){
            swap(brr[i],brr[i+1]);
        }
        i++;
    }
}
