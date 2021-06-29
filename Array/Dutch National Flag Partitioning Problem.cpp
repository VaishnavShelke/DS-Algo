
#include<iostream>
using namespace std;


//Three way partitioning of an array around a given range

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}


void threeWayPartition(int* arr,int n,int l,int h){


    int s_start = -1;
    int l_start = -1;

    for(int i = 0; i<n ; i++){
        if(arr[i]<l){
            s_start++;
            l_start++;
            swap(&arr[l_start],&arr[i]);
            swap(&arr[l_start],&arr[s_start]);
        }
        else if(arr[i]>=l && arr[i]<=h){
            l_start++;
            swap(&arr[i],&arr[l_start]);
        }
        else{}
        for (int i=0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    }

}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    threeWayPartition(arr, n, 20, 20);
 
    cout << "Modified array \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
