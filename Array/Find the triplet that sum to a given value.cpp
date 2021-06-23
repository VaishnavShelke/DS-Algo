#include<iostream>
#include<algorithm>
#define INF 99999
using namespace std;

int binarySearch(int* A,int low,int high,int num){

    return binary_search(A+low,A+high+1,num);
}

void find3Numbers(int* A,int size,int sum){

    sort(A,A+size);
    int i = INF;
    for(int k = 0; k<=size-3; k++){
        for(int j = k+1;j<=size-2 ; j++){
            i = binarySearch(A,j+1,size-1,sum-A[k]-A[j]);
            if(i){
                cout << "The triplet is exists " << endl;
                return;
            }
        }
    }
    cout << "Not Exist ";
    return;

}
int main()
{
    int A[] = { 1, 4, 6, 8, 10, 45};
    int sum = 22;
    int arr_size = sizeof(A) / sizeof(A[0]);
    //cout << binarySearch(A,0,5,45);
    find3Numbers(A, arr_size, sum);
    return 0;
}
