#include <iostream>
#include<stack>
using namespace std;

// Next Smaller Element

void printNSE(int* arr,int n){
    stack<int> stc;

    for(int i = 0; i<n ; i++){
        if(stc.empty()){
            stc.push(arr[i]);
        }
        else{
            if(stc.top()>arr[i]){
                while(!stc.empty() && stc.top()>arr[i]){
                    cout << stc.top() << " --->> " << arr[i] << endl;
                    stc.pop();
                }
                stc.push(arr[i]);
            }
            else{
                stc.push(arr[i]);
            }
        }
    }
    while(!stc.empty()){
        cout << stc.top() << " --->> " << -1 << endl;
        stc.pop();
    }
}

int main()
{
    int arr[]= {4, 8, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNSE(arr, n);
    return 0;
}
