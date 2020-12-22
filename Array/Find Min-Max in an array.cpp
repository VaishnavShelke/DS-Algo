#include <iostream>
#include <vector>
using namespace std;

// Finding min-max in an array

int main(){
    int arr[] = {4,22,5,3,565,7,6,45,643,346,436,4634,643634,634,64,46,464,64,63423,1,124,5};
    int minima,maxima;
    minima = 1e6;
    maxima = 1e-6;

    int length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < length;i++){
        maxima = max(arr[i],maxima);
        minima = min(arr[i],minima);
    }
    cout << "Maximum in array " << maxima;
    cout << "\nMinimum in array " << minima;
    return 0;
}
