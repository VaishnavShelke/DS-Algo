#include <iostream>
#include<queue>
using namespace std;

// Find Factorial of A very Large Number

void multiply(int num,int *arr,int& cap){
    int remainder = 0;
    int unit;

    for(int i = 0; i<cap; i++){
        unit = (num*arr[i] + remainder)%10;
        remainder = (num*arr[i] + remainder)/10;
        arr[i] = unit;
    }
    
    if(remainder != 0){
        while(remainder != 0){
            arr[cap]  = remainder%10;
            remainder = remainder/10;
            cap++;
        }
    }

}



void factorial(int Number){
    int answer[1000];
    int cap = 1;
    answer[0] = 1;
    for(int mult = 1; mult <= Number; mult++){
        multiply(mult,answer,cap);
    }
    for(int i = cap-1; i>=0 ; i--){
        cout << answer[i];
    }
    return;
}


int main()
{
    factorial(100);
    return 0;
}
