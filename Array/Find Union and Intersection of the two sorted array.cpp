#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

// A class to SHOW the intersection or union of two sorted arrays

class operations{
public:
    int *arr1;
    int *arr2;
    int len1,len2;

    operations(int arr1in[],int arr2in[],int l1,int l2);
    void show_union();
    void show_intersection();
};

operations :: operations (int arr1in[],int arr2in[],int l1,int l2){
    arr1 = arr1in;
    arr2 = arr2in;
    len1 = l1;
    len2 = l2;
}

void operations :: show_union(){
    int st2 = 0,st1 = 0;
    int unionarr[len1+len2];
    int ptr = 0;
    while(st1 < len1 || st2 < len2){
        if (st1 == len1) { while(st2 < len2) {unionarr[ptr] = arr2[st2]; st2++; ptr++;} continue;}

        if (st2 == len2) { while(st1 < len1) {unionarr[ptr] = arr1[st1]; st1++; ptr++;} continue;}

        if (arr1[st1] > arr2[st2]) { unionarr[ptr] = arr2[st2]; ptr++; st2++;}
        if (arr1[st1] < arr2[st2]) { unionarr[ptr] = arr1[st1]; ptr++;st1++;}
        if (arr1[st1] == arr2[st2]) { unionarr[ptr] = arr1[st1]; ptr++;st1++;st2++;}
    }
    for(int i = 0; i < ptr; i++){
        cout << unionarr[i] << " ";
    }
    cout << "\n";
}

void operations :: show_intersection(){
    int st2 = 0, st1 = 0;
    vector<int> intersection;

    while(st1 < len1 && st2 <len2){
        if (arr1[st1] > arr2[st2])  st2++;
        else if (arr1[st1] < arr2[st2])  st1++;
        else {intersection.push_back(arr1[st1]); st1++;st2++;}
    }
    for (int i = 0 ; i < intersection.size() ; i++) cout << intersection[i] << " ";
    cout << "\n";
}




int main(){
    int arr1[] = {1,22,33,44,55,66};
    int arr2[] = {3,22,26,33,34,44,46,55,67};
    int l1 = sizeof(arr1)/sizeof(arr1[0]);
    int l2 = sizeof(arr2)/sizeof(arr2[0]);
    operations op1(arr1,arr2,l1,l2);
    op1.show_union();
    op1.show_intersection();
    return 0;
}
