#include <iostream>
#include <typeinfo>
using namespace std;

// Find duplicates in an array of N + 1 integers
// Where all elements compulsorily belong to the range 1 -->> N

int main(){
    int arr[] = {1,3,4,5,6,1,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    int counter[len];
    for(int i = 0;i<len;i++) counter[i] = -1;

    for (int i = 0; i<len; i++){
        counter[arr[i]-1]++;
    }
    for(int i = 0; i<len ; i++){
        if (counter[i] > 0){
            cout << i+1 << " ";
        }
    }
}
