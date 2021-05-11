#include <iostream>
#include <bits\stdc++.h>

using namespace std;
// Experiment with a 2D array to pass it as an integer pointer of its first element
//  Rotate a square matrix by 90 without using extra sapce

void upisdown(int* arr, int ht, int lg);
void rotate90(int* arr,int ht, int lg){
    
    int temp;
    for(int j = 0; j<ht; j++){
        for(int i = 0; i < j; i++){
            temp = *(arr + i + j*lg);
            *(arr + i + j*lg) = *(arr + j + i*lg);
            *(arr + j + i*lg) = temp;
        }
    }
    upisdown(arr,ht,lg);
}

void upisdown(int* arr, int ht, int lg){

    int temp;
    for(int j = 0; j<ht/2 ; j++){
        for(int i = 0; i < lg ; i++){
            swap(*(arr + i + j*lg),*(arr + i + (ht-1-j)*lg));
        }
    }
}
int main(){
    int arr[4][4] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90(&arr[0][0],4,4);

    for(int j = 0; j<4 ; j++){
        for(int i = 0; i<4 ; i++){
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

