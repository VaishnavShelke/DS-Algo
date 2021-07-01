#include <bits/stdc++.h>
using namespace std;

// Arranging Amplifiers

bool comparebyPow(long long int a,long long int b){
    return pow(b,a) > pow(a,b);
}

int main(){
    int testcases;
    cin>>testcases;
    int amplifiers;
    long long int* arr;
    while(testcases){
        cin>>amplifiers;
        arr = new long long int[amplifiers];
        for(int i = 0; i<amplifiers ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+amplifiers,comparebyPow);
        for(int i = 0;i<amplifiers ; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        delete []arr;
        testcases--;
    }
}
